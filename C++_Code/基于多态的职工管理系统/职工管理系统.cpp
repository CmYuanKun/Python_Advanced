#include <iostream>
#include <string>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
using namespace std;

int main() 
{
	
	//ʵ���������߶���
	WorkerManager wm;
	
	int shoice = 0; //�����洢�û�ѡ��

	while (true)
	{
		//����չʾ�˵���Ա����
		wm.show_Menu();

		cout << "���������ѡ��" << endl;
		
		cin >> shoice;

		switch (shoice)
		{
		case 0:  //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:  //���ְ��
			wm.Add_Emp();
			break;
		case 2:  //��ʾְ��
			break;
		case 3:  //ɾ��ְ��
			break;
		case 4:  //�޸�ְ��
			break;
		case 5:  //����ְ��
			break;
		case 6:  //����ְ��
			break;
		case 7:  //����ĵ�
			break;
		default:
			system("cls");
			break;
		}


	}



	

	system("pause");
	return 0; 
}


