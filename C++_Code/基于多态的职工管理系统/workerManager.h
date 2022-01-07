#pragma once  //防止头文件重复注释
#include<iostream>
#include<fstream>
#include"worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"

#define FILENAME "empFile.txt"
using namespace std;  //使用标准命名空间

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void show_Menu();


	//退出系统
	void ExitSystem();

	//析构函数
	~WorkerManager();

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//读取文件中人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;

	//判断文件是否为空标记
	bool m_FilesEmpty;

private:

};

