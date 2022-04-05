#ifndef _EasyTcpClient_hpp_
#define _EasyTcpClient_hpp_

#ifdef _WIN32
	#define FD_SETSIZE 1024
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
	#include <Windows.h>
	#include <WinSock2.h>
	#pragma comment(lib,"ws2_32.lib")
#else
	#include<unistd.h>
	#include<arpa/inet.h>
	#include<string.h>

	#define SOCKET int
	#include INVALID_SOCKET  (SOCKET)(~0)
	#include SOCKET_ERROR            (-1)
#endif // _WIN32
#include <stdio.h>
#include "MessageHeader.hpp"

//缓冲区最小单元大小
#ifndef RECV_BUFF_SZIE
#define RECV_BUFF_SZIE 102400
#endif // !RECV_BUFF_SZIE


class EasyTcpClient
{
public:
	EasyTcpClient();
	virtual ~EasyTcpClient();
	void InitSocket();
	int Connect(const char *, unsigned short);
	bool OnRun();
	bool IsRun();
	virtual void OnNetMsg(DataHeader*);
	int SendData(DataHeader*);
	int RecvData(SOCKET);
	void Close();

private:
	int m_nCount;
	SOCKET m_sock;

	// 第二缓冲区 消息缓冲区
	char m_szMsgBuf[RECV_BUFF_SZIE * 10];
	//消息缓冲区的数据尾部位置
	int m_lastPos;
	//接收缓冲区
	char m_szRecv[RECV_BUFF_SZIE];
};

EasyTcpClient::EasyTcpClient()
{
	m_sock = INVALID_SOCKET;
	m_nCount = 0;
	memset(m_szMsgBuf, 0,sizeof(m_szMsgBuf));
	m_lastPos = 0;
	memset(m_szRecv, 0, sizeof(m_szRecv));
}

EasyTcpClient::~EasyTcpClient()
{
	Close();
}

void EasyTcpClient::InitSocket()
{
#ifdef _WIN32
	//启动Windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	int nRes = WSAStartup(ver, &dat);
	if (0 != nRes){
		switch (nRes)
		{
		case WSASYSNOTREADY: printf("重启电脑，或者检查网络库");   break;
		case WSAVERNOTSUPPORTED: printf("请更新网络库");  break;
		case WSAEINPROGRESS: printf("请重新启动");  break;
		case WSAEPROCLIM:  printf("请关闭不必要的软件，以确保有足够的网络资源"); break;
		}
	}
#endif
	if (INVALID_SOCKET != m_sock)
	{
		printf("<socket = %d>关闭旧连接...\n", m_sock);
		Close();
	}

	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == m_sock){
		printf("错误, 建立Socket失败...\n");
	}
	else{
		printf("建立Socket = <%d>成功...\n", m_sock);
	}
}

//连接服务器
int EasyTcpClient::Connect(const char* ip, unsigned short port)
{
	if (INVALID_SOCKET == m_sock)
	{
		InitSocket();
	}
	//连接服务器 connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(port);
#ifdef _WIN32
	_sin.sin_addr.S_un.S_addr = inet_addr(ip);
#else
	_sin.sin_addr.s_addr = inet_addr(ip);
#endif
	printf("<socket = %d>正在连接服务器<%s:%d>...\n", m_sock, ip, port);
	int ret = connect(m_sock, (sockaddr *)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		printf("<socket = %d>错误，连接服务器<%s:%d>失败...\n", m_sock, ip, port);
	}
	else {
		printf("<socket = %d>连接服务器<%s:%d>成功...\n", m_sock, ip, port);
	}
	return ret;
}


int EasyTcpClient::RecvData(SOCKET cSock)
{
	//接受数据 处理粘包 拆包
	int nLen = (int)recv(cSock, m_szRecv, RECV_BUFF_SZIE, 0);
	if (nLen < 0)
	{
		printf("<socket = %d>与服务器断开连接，任务结束。\n", cSock);
		return -1;
	}

	//将收取到的数据拷贝到消息缓存区
	memcpy(m_szMsgBuf + m_lastPos, m_szRecv, nLen);

	//消息缓冲区的数据尾部位置后移
	m_lastPos += nLen;

	//判断消息缓冲区的数据长度大于消息头DataHeader长度
	while (m_lastPos >= sizeof(DataHeader))
	{
		//这时就可以知道当前消息长度
		DataHeader* header = (DataHeader*)m_szMsgBuf;
		//判断消息缓冲区的数据长度大于消息长度
		if (m_lastPos >= header->dataLength)
		{
			//消息缓冲区剩余未处理数据长度
			int nSize = m_lastPos - header->dataLength;
			//处理网络信息
			OnNetMsg(header);
			//将消息缓冲区剩余未处理数据迁移
			memcpy(m_szMsgBuf, m_szMsgBuf + header->dataLength, nSize);
			//消息缓冲区的数据尾部位置前移
			m_lastPos = nSize;
		}
		else {
			//消息缓冲区剩余数据不够一调完整消息
			break;
		}
	}
	return 0;
}

//处理网络消息
bool EasyTcpClient::OnRun()
{
	if (IsRun())
	{
		fd_set fdReads;
		FD_ZERO(&fdReads);
		FD_SET(m_sock, &fdReads);

		timeval t = { 0, 0 };
		int ret = select(m_sock + 1, &fdReads, 0, 0, &t);
		if (ret < 0)
		{
			printf("<socket = %d>select任务结束! \n", m_sock);
			Close();
			return false;
		}
		if (FD_ISSET(m_sock, &fdReads))
		{
			FD_CLR(m_sock, &fdReads);
			if (-1 == RecvData(m_sock))
			{
				printf("<socket = %d>select 任务结束！ \n", m_sock);
				Close();
				return false;
			}
		}
		return true;
	}
	return false;
}

//是否工作中
bool EasyTcpClient::IsRun()
{
	return m_sock != INVALID_SOCKET;
}

void EasyTcpClient::OnNetMsg(DataHeader* header)
{
	switch (header ->cmd)
	{
	case CMD_LOGIN_RESULT:
		{
			LoginResult* login = (LoginResult*)header;
		}
		break;
	case CMD_LOGOUT_RESULT:
		{
			LogoutResult* logout = (LogoutResult*)header;
		}
		break;
	case CMD_NEW_USER_JOIN:
		{
			NewUserJoin* userJoin = (NewUserJoin*)header;
		}
	break;
	case CMD_ERROR:
		{
		printf("<socket=%d>收到服务端消息：CMD_ERROR,数据长度：%d\n", m_sock, header->dataLength);
		}
		break;
	default:
		{
		printf("<socket=%d>收到未定义消息,数据长度：%d\n", m_sock, header->dataLength);
		}
	}
}

int EasyTcpClient::SendData(DataHeader* header)
{
	if (IsRun() && header)
	{
		return send(m_sock, (const char*)header, header->dataLength, 0);
	}
	return SOCKET_ERROR;
}


//关闭套接字close socket
void EasyTcpClient::Close()
{
	if (m_sock != INVALID_SOCKET) {
#ifdef _WIN32
		closesocket(m_sock);
		//清除Windows socket环境
		WSACleanup();
#else
		close(m_sock);
#endif // !_WIN32
		m_sock = INVALID_SOCKET;
	}
}




#endif //!_EasyTcpClient_hpp_
