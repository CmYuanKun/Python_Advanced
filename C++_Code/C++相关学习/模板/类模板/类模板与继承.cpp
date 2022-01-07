#include <iostream>
#include <string>

using namespace std;

//如果父类是类模板，子类需要指定出父类中T的数据类型

template<class T>
class Base
{
    T m;
};

//class Son:public Base{}; //错误，C++编译需要子类分配内存，必须知道父类的T类型

class Son:public Base<int>
{

};

void test01()
{
    Son c;
}


//类模板继承类模板，可以用T2指定父类中的T类型
template<class T1, class T2>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

void test02()
{
	Son2<int, char> child1;
}

int main()
{
   test02();
   //system("pause");
   return 0;
}
