#pragma once  //��ֹͷ�ļ��ظ�ע��
#include<iostream>
#include<fstream>
#include"worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"

#define FILENAME "empFile.txt"
using namespace std;  //ʹ�ñ�׼�����ռ�

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void show_Menu();


	//�˳�ϵͳ
	void ExitSystem();

	//��������
	~WorkerManager();

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//��ȡ�ļ�������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ�ձ��
	bool m_FilesEmpty;

private:

};

