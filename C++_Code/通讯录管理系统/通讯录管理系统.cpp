
//封装函数显示该界面 如void showMenu()
//在main函数中调用封装好的函数
#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

//联系人结构体
struct Person 
{
	string m_Name;  //姓名
	int m_Sex;  //性别
	int m_Age;  //年龄
	string m_Phone; //电话
	string m_Addr; //地址
};

//通讯录结构体
struct Addressbooks 
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};



//显示菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1. 添加联系人  *****" << endl;
	cout << "*****  2. 显示联系人  *****" << endl;
	cout << "*****  3. 删除联系人  *****" << endl;
	cout << "*****  4. 查找联系人  *****" << endl;
	cout << "*****  5. 修改联系人  *****" << endl;
	cout << "*****  6. 清空联系人  *****" << endl;
	cout << "*****  0. 退出通讯录  *****" << endl; 
	cout << "**************************" << endl;
}


//添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录中是否人员已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}

	//输入姓名
	string name;
	cout << "请输入姓名： " << endl;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;



	// 输入性别
	int sex = 0;
	while (true) 
	{
		cout << "请输入性别： " << endl;
		cout << "1 --- 男： " << endl;
		cout << "2 --- 女： " << endl;

		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		cout << "输入有误，重新输入" << endl;
	
	}
	
	//输入年龄
	int age = 0;
	cout << "请输入年龄： " << endl;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;


	//输入联系电话
	string phone;
	cout << "请输入联系电话： " << endl;
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;


	//输入地址
	string addr;
	cout << "请输入地址： " << endl;
	cin >> addr;
	abs->personArray[abs->m_Size].m_Addr = addr;

	//更新通讯中人数
	abs->m_Size++;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");//清屏
	return;
}

//显示联系人
void showPerson(Addressbooks* abs) 
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录中无记录" << endl;
		return;
	}
	else {
		for (int i = 0;i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男":"女" )<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
			
	}

	system("pause");
	system("cls");//清屏
	return;
}

//查询联系人是否存在
int isExist(Addressbooks* abs, string name)
{
	//输入需要查找姓名 
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i; //如果找到找到返回数组中的索引
		}
	}
	return -1;  //如果没有遍历结束都没有找到，返回-1
}



//删除联系人
void deletePerson(Addressbooks* abs)
{
	//输入需要删除姓名
	string name;
	cout << "请输入需要删除姓名： " << endl;
	cin >> name;
	
	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "通讯录中无记录,无法删除" << endl;
		return;
	}
	 
	for (int i = ret; i < abs->m_Size; i++)
	{
		//数据前移
		abs->personArray[i] = abs->personArray[i + 1];

	}
	abs->m_Size--;  //更新通讯录中人员数
	cout << "删除成功" << endl;
	system("pause");
	system("cls");//清屏
	return;
	
}


//查找指定联系人
void findPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入需要查找姓名： " << endl;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "通讯录中无记录,无法查找" << endl;
		return;
	}

	//数据前移
	cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
	cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
	cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
	cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
	cout << "地址：" << abs->personArray[ret].m_Addr << endl;

	system("pause");
	system("cls");//清屏
	return;

}

//修改指定联系人信息
void modifyPerson(Addressbooks* abs) 
{
	string name;
	cout << "请输入需要修改姓名： " << endl;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "通讯录中无记录,无法修改" << endl;
		return;
	}


	//输入姓名
	string nameNew;
	cout << "请输入姓名： " << endl;
	cin >> nameNew;
	abs->personArray[ret].m_Name = nameNew;

	// 输入性别
	int sex = 0;
	while (true)
	{
		cout << "请输入性别： " << endl;
		cout << "1 --- 男： " << endl;
		cout << "2 --- 女： " << endl;

		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[ret].m_Sex = sex;
			break;
		}
		cout << "输入有误，重新输入" << endl;

	}

	//输入年龄
	int age = 0;
	cout << "请输入年龄： " << endl;
	cin >> age;
	abs->personArray[ret].m_Age = age;


	//输入联系电话
	string phone;
	cout << "请输入联系电话： " << endl;
	cin >> phone;
	abs->personArray[ret].m_Phone = phone;


	//输入地址
	string addr;
	cout << "请输入地址： " << endl;
	cin >> addr;
	abs->personArray[ret].m_Addr = addr;

	cout << "修改成功" << endl;

	system("pause");
	system("cls");//清屏
	return;
}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;  //将当前记录删除人数量为0
	cout << "通讯录为空" << endl;

	return;
}



int main(){
	//创建通讯录结构体变量
	Addressbooks abs;

	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	
	int select = 0; //创建用户选择输入的变量

	while (true) {

		//菜单显示调用
		showMenu();
		cin >> select;
		

		switch(select)
		{
			case 1:  //添加联系人
				addPerson(&abs);
				break;
			case 2:  //显示联系人
				showPerson(&abs);
				break;
			case 3:  //删除联系人
				deletePerson(&abs);
				break;
			case 4:  //查找联系人
				findPerson(&abs);
				break;
			case 5:  //修改联系人
				modifyPerson(&abs);
				break;
			case 6:  //清空联系人
				cleanPerson(&abs);
				break;
			case 0:  //退出通讯录
				cout << "欢迎下次再使用" << endl;
				system("pause");
				return 0;
			default:
				cout << "输入选择错误" << endl;
				break;
		}
	}

	

	system("pause");
	return 0;
}


