#include <iostream>
#include <string>

using namespace std;

//��ģ��
//��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
//��ģ���е�ģ������б������Ĭ�ϲ���

template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }

    void showPerson()
    {
        cout << "name: " << this->mName << " age: "<< this->mAge << endl;
    }

    NameType mName;
    AgeType mAge;

};

//��ģ��û���Զ������Ƶ���ʹ�÷�ʽ

void test01()
{
    Person<string, int>p("�����", 1000);
    p.showPerson();

    Person<string>p1("��˽�" , 100);
    p1.showPerson();

}



int main()
{
   test01();
   //system("pause");
   return 0;
}
