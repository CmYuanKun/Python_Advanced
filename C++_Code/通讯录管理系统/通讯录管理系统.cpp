
//��װ������ʾ�ý��� ��void showMenu()
//��main�����е��÷�װ�õĺ���
#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

//��ϵ�˽ṹ��
struct Person 
{
	string m_Name;  //����
	int m_Sex;  //�Ա�
	int m_Age;  //����
	string m_Phone; //�绰
	string m_Addr; //��ַ
};

//ͨѶ¼�ṹ��
struct Addressbooks 
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};



//��ʾ�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1. �����ϵ��  *****" << endl;
	cout << "*****  2. ��ʾ��ϵ��  *****" << endl;
	cout << "*****  3. ɾ����ϵ��  *****" << endl;
	cout << "*****  4. ������ϵ��  *****" << endl;
	cout << "*****  5. �޸���ϵ��  *****" << endl;
	cout << "*****  6. �����ϵ��  *****" << endl;
	cout << "*****  0. �˳�ͨѶ¼  *****" << endl; 
	cout << "**************************" << endl;
}


//�����ϵ��
void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼���Ƿ���Ա����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}

	//��������
	string name;
	cout << "������������ " << endl;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;



	// �����Ա�
	int sex = 0;
	while (true) 
	{
		cout << "�������Ա� " << endl;
		cout << "1 --- �У� " << endl;
		cout << "2 --- Ů�� " << endl;

		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		cout << "����������������" << endl;
	
	}
	
	//��������
	int age = 0;
	cout << "���������䣺 " << endl;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;


	//������ϵ�绰
	string phone;
	cout << "��������ϵ�绰�� " << endl;
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;


	//�����ַ
	string addr;
	cout << "�������ַ�� " << endl;
	cin >> addr;
	abs->personArray[abs->m_Size].m_Addr = addr;

	//����ͨѶ������
	abs->m_Size++;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");//����
	return;
}

//��ʾ��ϵ��
void showPerson(Addressbooks* abs) 
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼���޼�¼" << endl;
		return;
	}
	else {
		for (int i = 0;i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
			
	}

	system("pause");
	system("cls");//����
	return;
}

//��ѯ��ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	//������Ҫ�������� 
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i; //����ҵ��ҵ����������е�����
		}
	}
	return -1;  //���û�б���������û���ҵ�������-1
}



//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	//������Ҫɾ������
	string name;
	cout << "��������Ҫɾ�������� " << endl;
	cin >> name;
	
	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "ͨѶ¼���޼�¼,�޷�ɾ��" << endl;
		return;
	}
	 
	for (int i = ret; i < abs->m_Size; i++)
	{
		//����ǰ��
		abs->personArray[i] = abs->personArray[i + 1];

	}
	abs->m_Size--;  //����ͨѶ¼����Ա��
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");//����
	return;
	
}


//����ָ����ϵ��
void findPerson(Addressbooks* abs)
{
	string name;
	cout << "��������Ҫ���������� " << endl;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "ͨѶ¼���޼�¼,�޷�����" << endl;
		return;
	}

	//����ǰ��
	cout << "������" << abs->personArray[ret].m_Name << "\t";
	cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
	cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
	cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
	cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;

	system("pause");
	system("cls");//����
	return;

}

//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) 
{
	string name;
	cout << "��������Ҫ�޸������� " << endl;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1)
	{
		cout << "ͨѶ¼���޼�¼,�޷��޸�" << endl;
		return;
	}


	//��������
	string nameNew;
	cout << "������������ " << endl;
	cin >> nameNew;
	abs->personArray[ret].m_Name = nameNew;

	// �����Ա�
	int sex = 0;
	while (true)
	{
		cout << "�������Ա� " << endl;
		cout << "1 --- �У� " << endl;
		cout << "2 --- Ů�� " << endl;

		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[ret].m_Sex = sex;
			break;
		}
		cout << "����������������" << endl;

	}

	//��������
	int age = 0;
	cout << "���������䣺 " << endl;
	cin >> age;
	abs->personArray[ret].m_Age = age;


	//������ϵ�绰
	string phone;
	cout << "��������ϵ�绰�� " << endl;
	cin >> phone;
	abs->personArray[ret].m_Phone = phone;


	//�����ַ
	string addr;
	cout << "�������ַ�� " << endl;
	cin >> addr;
	abs->personArray[ret].m_Addr = addr;

	cout << "�޸ĳɹ�" << endl;

	system("pause");
	system("cls");//����
	return;
}

//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;  //����ǰ��¼ɾ��������Ϊ0
	cout << "ͨѶ¼Ϊ��" << endl;

	return;
}



int main(){
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;

	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	
	int select = 0; //�����û�ѡ������ı���

	while (true) {

		//�˵���ʾ����
		showMenu();
		cin >> select;
		

		switch(select)
		{
			case 1:  //�����ϵ��
				addPerson(&abs);
				break;
			case 2:  //��ʾ��ϵ��
				showPerson(&abs);
				break;
			case 3:  //ɾ����ϵ��
				deletePerson(&abs);
				break;
			case 4:  //������ϵ��
				findPerson(&abs);
				break;
			case 5:  //�޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6:  //�����ϵ��
				cleanPerson(&abs);
				break;
			case 0:  //�˳�ͨѶ¼
				cout << "��ӭ�´���ʹ��" << endl;
				system("pause");
				return 0;
			default:
				cout << "����ѡ�����" << endl;
				break;
		}
	}

	

	system("pause");
	return 0;
}


