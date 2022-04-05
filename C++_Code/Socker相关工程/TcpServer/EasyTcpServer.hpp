#ifndef _EasyTcpServer_hpp_
#define _EasyTcpServer_hpp_

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
	#include<windows.h>
	#include<WinSock2.h>
	#pragma comment(lib,"ws2_32.lib")
#else
	#include<unistd.h> //uni std
	#include<arpa/inet.h>
	#include<string.h>

	#define SOCKET int
	#define INVALID_SOCKET  (SOCKET)(~0)
	#define SOCKET_ERROR            (-1)
#endif

#include <stdio.h>
#include <vector>
#include "MessageHeader.hpp"

//缓冲区最小单元大小
#ifndef RECV_BUFF_SZIE
#define RECV_BUFF_SZIE 102400
#endif // !RECV_BUFF_SZIE

using namespace std;


class ClientSocket
{
public:
	ClientSocket(SOCKET);
	~ClientSocket();

	SOCKET Sockfd();
	char* MsgBuf();
	int GetLastPos();
	void SetLastPos(int);


private:
	SOCKET m_sockfd;
	//第二缓冲区 消息缓冲区
	char m_szMsgBuf[RECV_BUFF_SZIE * 10];
	//消息缓冲区的数据尾部位置
	int m_lastPos;
};

ClientSocket::ClientSocket(SOCKET sockfd = INVALID_SOCKET)
{
	m_sockfd = sockfd;
	memset(m_szMsgBuf, 0 , sizeof(m_szMsgBuf));
	m_lastPos = 0;
}

ClientSocket::~ClientSocket()
{
}

SOCKET ClientSocket::Sockfd()
{
	return m_sockfd;
}

char* ClientSocket::MsgBuf()
{
	return m_szMsgBuf;
}

int ClientSocket::GetLastPos()
{
	return m_lastPos;
}
void ClientSocket::SetLastPos(int pos)
{
	m_lastPos = pos;
}





class EasyTcpServer
{
public:
	EasyTcpServer();
	~EasyTcpServer();
	SOCKET InitSocket();
	int Bind(const char*, unsigned short);
	int Listen(int);
	SOCKET Accept();
	void Close();
	bool OnRun();
	bool IsRun();
	int RecvData(ClientSocket*);
	int SendData(SOCKET, DataHeader*);
	virtual void OnNetMsg(SOCKET, DataHeader*);
	void SendDataToAll(DataHeader*);

private:
	SOCKET m_sock;
	vector<ClientSocket*> m_clients;
	//缓冲区
	char m_szRecv[RECV_BUFF_SZIE];
};

EasyTcpServer::EasyTcpServer()
{
	m_sock = INVALID_SOCKET;
	memset(m_szRecv, 0, RECV_BUFF_SZIE);
}

EasyTcpServer::~EasyTcpServer()
{
	Close();
}

//初始化Socket
SOCKET EasyTcpServer::InitSocket()
{
#ifdef _WIN32
	//启动Windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	int nRes = WSAStartup(ver, &dat);
	if (0 != nRes) {
		switch (nRes)
		{
		case WSASYSNOTREADY: printf("重启电脑，或者检查网络库");   break;
		case WSAVERNOTSUPPORTED: printf("请更新网络库");  break;
		case WSAEINPROGRESS: printf("请重新启动");  break;
		case WSAEPROCLIM:  printf("请关闭不必要的软件，以确保有足够的网络资源"); break;
		}
	}
#endif // _WIN32
	if (INVALID_SOCKET != m_sock)
	{
		printf("<socket = %d>关闭旧连接...\n", (int)m_sock);
		Close();
	}
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == m_sock)
	{
		printf("错误，建立socket失败...\n");
	}
	else {
		printf("建立socket = %d 成功...\n",(int)m_sock);
	}
	return m_sock;
}

//bind 绑定用于接受客户端连接的网络端口
int EasyTcpServer::Bind(const char* ip, unsigned short port)
{
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(port);
#ifdef _WIN32
	if (ip)
	{
		_sin.sin_addr.S_un.S_addr = inet_addr(ip);
	}
	else {
		_sin.sin_addr.S_un.S_addr = INADDR_ANY;
	}
#else
	if (ip)
	{
		_sin.sin_addr.s_addr = inet_addr(ip);
	}
	else {
		_sin.sin_addr.s_addr = INADDR_ANY;
	}
#endif // _WIN32
	int ret = bind(m_sock, (sockaddr*)&_sin, sizeof(_sin));
	if (SOCKET_ERROR == ret)
	{
		printf("错误，绑定网络端口<%d>失败...\n", port);
	}
	else {
		printf("绑定网络端口<%d>成功...\n", port);
	}
	return ret;
}

//监听端口号
int EasyTcpServer::Listen(int n)
{
	int ret = listen(m_sock, n);
	if (SOCKET_ERROR == ret)
	{
		printf("socket=<%d>错误,监听网络端口失败...\n", m_sock);
	}
	else {
		printf("socket=<%d>监听网络端口成功...\n", m_sock);
	}
	return ret;

}

SOCKET EasyTcpServer::Accept()
{
	//accept 等待接受客户端连接
	sockaddr_in clientAddr = {};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET cSock = INVALID_SOCKET;
#ifdef _WIN32
	cSock = accept(m_sock, (sockaddr*)&clientAddr, &nAddrLen);
#else
	cSock = accept(_sock, (sockaddr*)&clientAddr, (socklen_t*)&nAddrLen);
#endif // _WIN32
	if (INVALID_SOCKET == cSock)
	{
		printf("socket=<%d>错误,接受到无效客户端SOCKET...\n", (int)m_sock);
	}
	else
	{
		NewUserJoin userJoin;
		SendDataToAll(&userJoin);
		m_clients.push_back(new ClientSocket(cSock));
		printf("socket=<%d>新客户端加入：socket = %d,IP = %s \n", (int)m_sock, (int)cSock, inet_ntoa(clientAddr.sin_addr));
	}
	return cSock;
}

bool EasyTcpServer::OnRun()
{
	if(IsRun())
	{
		//伯克利套接字BSD socket
		fd_set fdRead; //描述符socket 集合
		fd_set fdWrite;
		fd_set fdExp;
		//清除集合
		FD_ZERO(&fdRead);
		FD_ZERO(&fdWrite);
		FD_ZERO(&fdExp);
		//将描述符socket 加入集合
		FD_SET(m_sock, &fdRead);
		FD_SET(m_sock, &fdWrite);
		FD_SET(m_sock, &fdExp);

		SOCKET maxSock = m_sock;
		for (int n = (int)m_clients.size() - 1; n >= 0; n--)
		{
			FD_SET(m_clients[n]->Sockfd(), &fdRead);
			if (maxSock < m_clients[n]->Sockfd())
			{
				maxSock = m_clients[n]->Sockfd();
			}
		}
		//nfds 是一个整数值 是指fd_set集合中所有描述符(socket)的范围，而不是数量
		//既是所有文件描述符最大值+1 在Windows中这个参数可以写0
		timeval t = { 1,0 };
		int ret = select(maxSock + 1, &fdRead, &fdWrite, &fdExp, &t); 
		if (ret < 0)
		{
			printf("select任务结束。\n");
			Close();
			return false;
		}
		//判断描述符（socket）是否在集合中
		if (FD_ISSET(m_sock, &fdRead))
		{
			FD_CLR(m_sock, &fdRead);
			Accept();
		}
		for (int n = (int)m_clients.size() - 1; n >= 0; n--)
		{
			if (FD_ISSET(m_clients[n]->Sockfd(), &fdRead))
			{
				if (-1 == RecvData(m_clients[n]))
				{
					//std::vector<SOCKET>::iterator
					auto iter = m_clients.begin() + n;
					if (iter != m_clients.end())
					{
						delete m_clients[n];
						m_clients.erase(iter);
					}
				}
			}
		}
		return true;
	}
	return false;
}

//是否工作中
bool EasyTcpServer::IsRun()
{
	return m_sock != INVALID_SOCKET;
}

int EasyTcpServer::RecvData(ClientSocket* pClient)
{
	// 5 接收客户端数据
	int nLen = (int)recv(pClient->Sockfd(), m_szRecv, RECV_BUFF_SZIE, 0);
	//printf("nLen=%d\n", nLen);
	if (nLen <= 0)
	{
		printf("客户端<Socket=%d>已退出，任务结束。\n", pClient->Sockfd());
		return -1;
	}
	//将收取到的数据拷贝到消息缓冲区
	memcpy(pClient->MsgBuf() + pClient->GetLastPos(), m_szRecv, nLen);
	//消息缓冲区的数据尾部位置后移
	pClient->SetLastPos(pClient->GetLastPos() + nLen);

	//判断消息缓冲区的数据长度大于消息头DataHeader长度
	while (pClient->GetLastPos() >= sizeof(DataHeader))
	{
		//这时就可以知道当前消息的长度
		DataHeader* header = (DataHeader*)pClient->MsgBuf();
		//判断消息缓冲区的数据长度大于消息长度
		if (pClient->GetLastPos() >= header->dataLength)
		{
			//消息缓冲区剩余未处理数据的长度
			int nSize = pClient->GetLastPos() - header->dataLength;
			//处理网络消息
			OnNetMsg(pClient->Sockfd(), header);
			//将消息缓冲区剩余未处理数据前移
			memcpy(pClient->MsgBuf(), pClient->MsgBuf() + header->dataLength, nSize);
			//消息缓冲区的数据尾部位置前移
			pClient->SetLastPos(nSize);
		}
		else {
			//消息缓冲区剩余数据不够一条完整消息
			break;
		}
	}
	return 0;
}

void EasyTcpServer::OnNetMsg(SOCKET cSock, DataHeader* header)
{
	switch (header->cmd)
	{
	case CMD_LOGIN:
	{

		Login* login = (Login*)header;
		//printf("收到客户端<Socket=%d>请求：CMD_LOGIN,数据长度：%d,userName=%s PassWord=%s\n", cSock, login->dataLength, login->userName, login->PassWord);
		//忽略判断用户密码是否正确的过程
		LoginResult ret;
		SendData(cSock, &ret);
	}
	break;
	case CMD_LOGOUT:
	{
		Logout* logout = (Logout*)header;
		//printf("收到客户端<Socket=%d>请求：CMD_LOGOUT,数据长度：%d,userName=%s \n", cSock, logout->dataLength, logout->userName);
		//忽略判断用户密码是否正确的过程
		LogoutResult ret;
		SendData(cSock, &ret);
	}
	break;
	default:
	{
		printf("<socket=%d>收到未定义消息,数据长度：%d\n", cSock, header->dataLength);
		//DataHeader ret;
		//SendData(cSock, &ret);
	}
	break;
	}
}

//发送指定Socket数据
int EasyTcpServer::SendData(SOCKET cSock, DataHeader* header)
{
	if (IsRun() && header)
	{
		return send(cSock, (const char*)header, header->dataLength, 0);
	}
	return SOCKET_ERROR;
}

void EasyTcpServer::SendDataToAll(DataHeader* header)
{
	for (int n = (int)m_clients.size() - 1; n >= 0; n--)
	{
		SendData(m_clients[n]->Sockfd(), header);
	}

}

void EasyTcpServer::Close()
{
	if (m_sock != INVALID_SOCKET)
	{
#ifdef _WIN32
		for (int n = (int)m_clients.size() - 1; n >= 0; n--)
		{
			closesocket(m_clients[n]->Sockfd());
			delete m_clients[n];
		}
		//关闭套接字closesocket
		closesocket(m_sock);
		//清除windows socket环境
		WSACleanup();
#else
		for (int n = (int)m_clients.size() - 1; n >= 0; n--)
		{
			close(m_clients[n]->Sockfd());
			delete m_clients[n];
		}
		//关闭套接字closesocket
		close(m_sock);
#endif // _WIN32
		m_clients.clear();
	}
}

#endif // !_EasyTcpServer_hpp_