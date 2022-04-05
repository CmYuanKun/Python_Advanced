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

//��������С��Ԫ��С
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
	//�ڶ������� ��Ϣ������
	char m_szMsgBuf[RECV_BUFF_SZIE * 10];
	//��Ϣ������������β��λ��
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
	//������
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

//��ʼ��Socket
SOCKET EasyTcpServer::InitSocket()
{
#ifdef _WIN32
	//����Windows socket 2.x����
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	int nRes = WSAStartup(ver, &dat);
	if (0 != nRes) {
		switch (nRes)
		{
		case WSASYSNOTREADY: printf("�������ԣ����߼�������");   break;
		case WSAVERNOTSUPPORTED: printf("����������");  break;
		case WSAEINPROGRESS: printf("����������");  break;
		case WSAEPROCLIM:  printf("��رղ���Ҫ���������ȷ�����㹻��������Դ"); break;
		}
	}
#endif // _WIN32
	if (INVALID_SOCKET != m_sock)
	{
		printf("<socket = %d>�رվ�����...\n", (int)m_sock);
		Close();
	}
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == m_sock)
	{
		printf("���󣬽���socketʧ��...\n");
	}
	else {
		printf("����socket = %d �ɹ�...\n",(int)m_sock);
	}
	return m_sock;
}

//bind �����ڽ��ܿͻ������ӵ�����˿�
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
		printf("���󣬰�����˿�<%d>ʧ��...\n", port);
	}
	else {
		printf("������˿�<%d>�ɹ�...\n", port);
	}
	return ret;
}

//�����˿ں�
int EasyTcpServer::Listen(int n)
{
	int ret = listen(m_sock, n);
	if (SOCKET_ERROR == ret)
	{
		printf("socket=<%d>����,��������˿�ʧ��...\n", m_sock);
	}
	else {
		printf("socket=<%d>��������˿ڳɹ�...\n", m_sock);
	}
	return ret;

}

SOCKET EasyTcpServer::Accept()
{
	//accept �ȴ����ܿͻ�������
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
		printf("socket=<%d>����,���ܵ���Ч�ͻ���SOCKET...\n", (int)m_sock);
	}
	else
	{
		NewUserJoin userJoin;
		SendDataToAll(&userJoin);
		m_clients.push_back(new ClientSocket(cSock));
		printf("socket=<%d>�¿ͻ��˼��룺socket = %d,IP = %s \n", (int)m_sock, (int)cSock, inet_ntoa(clientAddr.sin_addr));
	}
	return cSock;
}

bool EasyTcpServer::OnRun()
{
	if(IsRun())
	{
		//�������׽���BSD socket
		fd_set fdRead; //������socket ����
		fd_set fdWrite;
		fd_set fdExp;
		//�������
		FD_ZERO(&fdRead);
		FD_ZERO(&fdWrite);
		FD_ZERO(&fdExp);
		//��������socket ���뼯��
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
		//nfds ��һ������ֵ ��ָfd_set����������������(socket)�ķ�Χ������������
		//���������ļ����������ֵ+1 ��Windows�������������д0
		timeval t = { 1,0 };
		int ret = select(maxSock + 1, &fdRead, &fdWrite, &fdExp, &t); 
		if (ret < 0)
		{
			printf("select���������\n");
			Close();
			return false;
		}
		//�ж���������socket���Ƿ��ڼ�����
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

//�Ƿ�����
bool EasyTcpServer::IsRun()
{
	return m_sock != INVALID_SOCKET;
}

int EasyTcpServer::RecvData(ClientSocket* pClient)
{
	// 5 ���տͻ�������
	int nLen = (int)recv(pClient->Sockfd(), m_szRecv, RECV_BUFF_SZIE, 0);
	//printf("nLen=%d\n", nLen);
	if (nLen <= 0)
	{
		printf("�ͻ���<Socket=%d>���˳������������\n", pClient->Sockfd());
		return -1;
	}
	//����ȡ�������ݿ�������Ϣ������
	memcpy(pClient->MsgBuf() + pClient->GetLastPos(), m_szRecv, nLen);
	//��Ϣ������������β��λ�ú���
	pClient->SetLastPos(pClient->GetLastPos() + nLen);

	//�ж���Ϣ�����������ݳ��ȴ�����ϢͷDataHeader����
	while (pClient->GetLastPos() >= sizeof(DataHeader))
	{
		//��ʱ�Ϳ���֪����ǰ��Ϣ�ĳ���
		DataHeader* header = (DataHeader*)pClient->MsgBuf();
		//�ж���Ϣ�����������ݳ��ȴ�����Ϣ����
		if (pClient->GetLastPos() >= header->dataLength)
		{
			//��Ϣ������ʣ��δ�������ݵĳ���
			int nSize = pClient->GetLastPos() - header->dataLength;
			//����������Ϣ
			OnNetMsg(pClient->Sockfd(), header);
			//����Ϣ������ʣ��δ��������ǰ��
			memcpy(pClient->MsgBuf(), pClient->MsgBuf() + header->dataLength, nSize);
			//��Ϣ������������β��λ��ǰ��
			pClient->SetLastPos(nSize);
		}
		else {
			//��Ϣ������ʣ�����ݲ���һ��������Ϣ
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
		//printf("�յ��ͻ���<Socket=%d>����CMD_LOGIN,���ݳ��ȣ�%d,userName=%s PassWord=%s\n", cSock, login->dataLength, login->userName, login->PassWord);
		//�����ж��û������Ƿ���ȷ�Ĺ���
		LoginResult ret;
		SendData(cSock, &ret);
	}
	break;
	case CMD_LOGOUT:
	{
		Logout* logout = (Logout*)header;
		//printf("�յ��ͻ���<Socket=%d>����CMD_LOGOUT,���ݳ��ȣ�%d,userName=%s \n", cSock, logout->dataLength, logout->userName);
		//�����ж��û������Ƿ���ȷ�Ĺ���
		LogoutResult ret;
		SendData(cSock, &ret);
	}
	break;
	default:
	{
		printf("<socket=%d>�յ�δ������Ϣ,���ݳ��ȣ�%d\n", cSock, header->dataLength);
		//DataHeader ret;
		//SendData(cSock, &ret);
	}
	break;
	}
}

//����ָ��Socket����
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
		//�ر��׽���closesocket
		closesocket(m_sock);
		//���windows socket����
		WSACleanup();
#else
		for (int n = (int)m_clients.size() - 1; n >= 0; n--)
		{
			close(m_clients[n]->Sockfd());
			delete m_clients[n];
		}
		//�ر��׽���closesocket
		close(m_sock);
#endif // _WIN32
		m_clients.clear();
	}
}

#endif // !_EasyTcpServer_hpp_