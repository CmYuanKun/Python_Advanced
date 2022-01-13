#include "workerManager.h"


WorkerManager::WorkerManager()
{
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������
		int m_EmpNum = 0;
		Worker** m_EmpArray = NULL;
		this->m_FilesEmpty = true;
		ifs.close();
		return;
	}
	//2�� �ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������
		int m_EmpNum = 0;
		Worker** m_EmpArray = NULL;
		this->m_FilesEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��"<< num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ������ݣ�����������
	this->init_Emp();

	for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
			<< " ְ�������� " << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}

//չʾ�˵�
void WorkerManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}


void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);


	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ������: " << endl;
	
	int addNum = 0; //�����û���������������

	cin >> addNum;

	if(addNum > 0)
	{
		//�¿ռ����� = ԭ����¼���� + ��������
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace = new Worker* [newSize];

		//��ԭ���ռ������ݣ��������¿ռ�
		if(this->m_EmpArray != NULL)
		{
			for(int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//��������µ�����

		for (int i = 0; i < addNum; i++)
		{
			int id; //ְ�����
			string name; //ְ������
			int dSelect; //����ѡ��

			cout <<"������� "<< i + 1 <<"����ְ�����" << endl;
			cin >> id;
			cout << "������� " << i + 1 << "����ְ������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1�� ��ְͨ��" << endl;
			cout << "2�� ����" << endl;
			cout << "3�� �ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//��������ְ��ָ�룬������������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize; 

		this->m_FilesEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����Ա��" << endl;

		//�������ݵ��ļ���
		this->save();

	}
	else 
	{
		cout << "������������" << endl;
	}

	system("pause");
	system("cls");
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}	

//��ʼ��ְ��

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else 
		{
			worker = new Boss(id, name, dId);
		}

		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}