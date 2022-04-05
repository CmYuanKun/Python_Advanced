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

//��������С��Ԫ��С
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

	// �ڶ������� ��Ϣ������
	char m_szMsgBuf[RECV_BUFF_SZIE * 10];
	//��Ϣ������������β��λ��
	int m_lastPos;
	//���ջ�����
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
	//����Windows socket 2.x����
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	int nRes = WSAStartup(ver, &dat);
	if (0 != nRes){
		switch (nRes)
		{
		case WSASYSNOTREADY: printf("�������ԣ����߼�������");   break;
		case WSAVERNOTSUPPORTED: printf("����������");  break;
		case WSAEINPROGRESS: printf("����������");  break;
		case WSAEPROCLIM:  printf("��رղ���Ҫ���������ȷ�����㹻��������Դ"); break;
		}
	}
#endif
	if (INVALID_SOCKET != m_sock)
	{
		printf("<socket = %d>�رվ�����...\n", m_sock);
		Close();
	}

	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == m_sock){
		printf("����, ����Socketʧ��...\n");
	}
	else{
		printf("����Socket = <%d>�ɹ�...\n", m_sock);
	}
}

//���ӷ�����
int EasyTcpClient::Connect(const char* ip, unsigned short port)
{
	if (INVALID_SOCKET == m_sock)
	{
		InitSocket();
	}
	//���ӷ����� connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(port);
#ifdef _WIN32
	_sin.sin_addr.S_un.S_addr = inet_addr(ip);
#else
	_sin.sin_addr.s_addr = inet_addr(ip);
#endif
	printf("<socket = %d>�������ӷ�����<%s:%d>...\n", m_sock, ip, port);
	int ret = connect(m_sock, (sockaddr *)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		printf("<socket = %d>�������ӷ�����<%s:%d>ʧ��...\n", m_sock, ip, port);
	}
	else {
		printf("<socket = %d>���ӷ�����<%s:%d>�ɹ�...\n", m_sock, ip, port);
	}
	return ret;
}


int EasyTcpClient::RecvData(SOCKET cSock)
{
	//�������� ����ճ�� ���
	int nLen = (int)recv(cSock, m_szRecv, RECV_BUFF_SZIE, 0);
	if (nLen < 0)
	{
		printf("<socket = %d>��������Ͽ����ӣ����������\n", cSock);
		return -1;
	}

	//����ȡ�������ݿ�������Ϣ������
	memcpy(m_szMsgBuf + m_lastPos, m_szRecv, nLen);

	//��Ϣ������������β��λ�ú���
	m_lastPos += nLen;

	//�ж���Ϣ�����������ݳ��ȴ�����ϢͷDataHeader����
	while (m_lastPos >= sizeof(DataHeader))
	{
		//��ʱ�Ϳ���֪����ǰ��Ϣ����
		DataHeader* header = (DataHeader*)m_szMsgBuf;
		//�ж���Ϣ�����������ݳ��ȴ�����Ϣ����
		if (m_lastPos >= header->dataLength)
		{
			//��Ϣ������ʣ��δ�������ݳ���
			int nSize = m_lastPos - header->dataLength;
			//����������Ϣ
			OnNetMsg(header);
			//����Ϣ������ʣ��δ��������Ǩ��
			memcpy(m_szMsgBuf, m_szMsgBuf + header->dataLength, nSize);
			//��Ϣ������������β��λ��ǰ��
			m_lastPos = nSize;
		}
		else {
			//��Ϣ������ʣ�����ݲ���һ��������Ϣ
			break;
		}
	}
	return 0;
}

//����������Ϣ
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
			printf("<socket = %d>select�������! \n", m_sock);
			Close();
			return false;
		}
		if (FD_ISSET(m_sock, &fdReads))
		{
			FD_CLR(m_sock, &fdReads);
			if (-1 == RecvData(m_sock))
			{
				printf("<socket = %d>select ��������� \n", m_sock);
				Close();
				return false;
			}
		}
		return true;
	}
	return false;
}

//�Ƿ�����
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
		printf("<socket=%d>�յ��������Ϣ��CMD_ERROR,���ݳ��ȣ�%d\n", m_sock, header->dataLength);
		}
		break;
	default:
		{
		printf("<socket=%d>�յ�δ������Ϣ,���ݳ��ȣ�%d\n", m_sock, header->dataLength);
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


//�ر��׽���close socket
void EasyTcpClient::Close()
{
	if (m_sock != INVALID_SOCKET) {
#ifdef _WIN32
		closesocket(m_sock);
		//���Windows socket����
		WSACleanup();
#else
		close(m_sock);
#endif // !_WIN32
		m_sock = INVALID_SOCKET;
	}
}




#endif //!_EasyTcpClient_hpp_
