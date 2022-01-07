#include <iostream>
#include <string>

using namespace std;
//利用具体化的模板，可以解决自定义类型的通用化
//学习模板并不是为了写模板，而是在STL能够运用系统提供的模板


//模板的通用性并不是万能的
//模板的重载，可以为特定的类型提供具体化的模板
// template<class T>
// void f(T a, T b)
// {
//     a = b;
// }

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};



//普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//具体化优先于常规模板
template<>
bool myCompare(Person& p1, Person& p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p1.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a = 10;
    int b = 10;

    //内置数据类型可以直接使用的函数模板
    bool ret = myCompare(a, b);

    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }

}



void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    //自定义数据类型，不会调用普通的函数模型
    //可以创建具体化的Person数据类型的模板，用于特殊处理这个类型

    bool ret = myCompare(p1, p2);
    if (ret)
    {
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}

}


int main()
{
   test01();
   test02();
   //system("pause");
   return 0;
}
