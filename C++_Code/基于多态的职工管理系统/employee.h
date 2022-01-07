#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"


class Employee :public Worker
{
public:
	//构造函数初始化参数列表
	Employee(int id, string name, int dId);

	//显示个人信息
	void showInfo();

	//获取岗位名称
	string getDeptName();

	~Employee();

};

