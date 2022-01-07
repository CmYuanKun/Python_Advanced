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
	
	//实例化管理者对象
	WorkerManager wm;
	
	int shoice = 0; //用来存储用户选项

	while (true)
	{
		//调用展示菜单成员函数
		wm.show_Menu();

		cout << "请输入你的选择" << endl;
		
		cin >> shoice;

		switch (shoice)
		{
		case 0:  //退出系统
			wm.ExitSystem();
			break;
		case 1:  //添加职工
			wm.Add_Emp();
			break;
		case 2:  //显示职工
			break;
		case 3:  //删除职工
			break;
		case 4:  //修改职工
			break;
		case 5:  //查找职工
			break;
		case 6:  //排序职工
			break;
		case 7:  //清空文档
			break;
		default:
			system("cls");
			break;
		}


	}



	

	system("pause");
	return 0; 
}


