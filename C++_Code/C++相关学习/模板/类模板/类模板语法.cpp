#include <iostream>
#include <string>

using namespace std;
//��ģ��
template<class NameType, class AgeType>
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


void test01()
{
    //ָ��NameTypeΪstring���ͣ� AgeTypeΪ int����
    Person<string, int>P1("�����", 999);
    P1.showPerson();
    
}

int main()
{
   test01();
   //system("pause");
   return 0;
}
