#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"


class Boss :public Worker
{
public:
	//���캯����ʼ�������б�
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDeptName();

	~Boss();

};

