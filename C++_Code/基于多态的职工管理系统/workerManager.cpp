#include "workerManager.h"


WorkerManager::WorkerManager()
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化属性
		int m_EmpNum = 0;
		Worker** m_EmpArray = NULL;
		this->m_FilesEmpty = true;
		ifs.close();
		return;
	}
	//2、 文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化属性
		int m_EmpNum = 0;
		Worker** m_EmpArray = NULL;
		this->m_FilesEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为："<< num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中数据，存在数组中
	this->init_Emp();

	for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "职工号： " << this->m_EmpArray[i]->m_Id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
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

//展示菜单
void WorkerManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}


void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
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
	cout << "请输入添加职工数量: " << endl;
	
	int addNum = 0; //保存用户的输入输入数量

	cin >> addNum;

	if(addNum > 0)
	{
		//新空间人数 = 原来记录人数 + 新增人数
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker ** newSpace = new Worker* [newSize];

		//将原来空间下数据，拷贝到新空间
		if(this->m_EmpArray != NULL)
		{
			for(int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新的数据

		for (int i = 0; i < addNum; i++)
		{
			int id; //职工编号
			string name; //职工姓名
			int dSelect; //部门选择

			cout <<"请输入第 "<< i + 1 <<"个新职工编号" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << "个新职工姓名" << endl;
			cin >> name;


			cout << "请选择该职工的岗位" << endl;
			cout << "1、 普通职工" << endl;
			cout << "2、 经理" << endl;
			cout << "3、 老板" << endl;
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

			//将创建的职工指针，保存在数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更新新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize; 

		this->m_FilesEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新员工" << endl;

		//保存数据到文件中
		this->save();

	}
	else 
	{
		cout << "输入数据有误" << endl;
	}

	system("pause");
	system("cls");
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件

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

//初始化职工

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

		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}