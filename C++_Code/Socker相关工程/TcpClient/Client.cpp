#include "EasyTcpClient.hpp"
#include <thread>
using namespace std;

bool g_bRun = true;

void cmdThread()
{
	while (true)
	{
		char cmdBuf[256] = {};
		scanf("%s", cmdBuf);
		
		if (0 == strcmp(cmdBuf, "exit"))
		{
			g_bRun = false;
			printf("退出cmdThread线程\n");
		}
		else {
			printf("不支持的命令。 \n");
		}
	}
}


int main()
{
	const int cCount = FD_SETSIZE - 1;
	//const int cCount = 1000;
	EasyTcpClient* client[cCount];

	for (int n = 0; n < cCount; n++)
	{
		client[n] = new EasyTcpClient();
	}

	for (int n = 0; n < cCount; n++)
	{
		client[n]->Connect("127.0.0.1", 4567);
	}

	//启动UI线程
	thread t1(cmdThread);
	t1.detach();

	Login login;
	strcpy(login.userName, "lyd");
	strcpy(login.passWord, "lydmm");

	while (g_bRun)
	{
		for (int n = 0; n < cCount; n++)
		{
			client[n]->SendData(&login);
			client[n]->OnRun();
		}
	}

	for (int n = 0; n < cCount; n++)
	{
		client[n]->Close();
	}
	printf("已退出。\n");
	getchar();
	return 0;
}