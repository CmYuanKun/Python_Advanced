#include <iostream>
#include <string>

using namespace std;

//类模板
//类模板使用只能用显示指定类型方式
//类模板中的模板参数列表可以有默认参数

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

//类模板没有自动类型推导的使用方式

void test01()
{
    Person<string, int>p("送悟空", 1000);
    p.showPerson();

    Person<string>p1("猪八戒" , 100);
    p1.showPerson();

}



int main()
{
   test01();
   //system("pause");
   return 0;
}
