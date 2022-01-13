#include <iostream>
#include <string>

using namespace std;

//ȫ�ֺ��������Ԫ ����ʵ�� ��


template<class T1, class T2> class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout<< "����ʵ��-- ����: " << p.m_Name << "����: " << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1��ȫ�ֺ��������Ԫ   ����ʵ��
	friend void printPerson(Person<T1, T2> & p)
	{
		cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
	}


	//ȫ�ֺ��������Ԫ  ����ʵ��
	friend void printPerson2<>(Person<T1, T2> & p);

public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;

};

void test01()
{

    Person <string, int >p("Tom", 20);
	printPerson(p);
}


int main()
{
   test01();
   //system("pause");
   return 0;
}
