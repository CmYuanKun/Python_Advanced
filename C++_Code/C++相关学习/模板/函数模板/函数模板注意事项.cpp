#include <iostream>
#include <string>

using namespace std;

//利用模板提供通用的交换函数
template<class T>
void mySwap(T &a, T& b)
{
   T temp = a;
   a = b;
   b = temp;
}

//自动化类型推导，必须推导出一致的数据类型T,才能使用
void test01()
{
   int a = 10;
   int b = 20;
   char c = 'c';

   mySwap(a, b);
   cout << "a = " << a << " b= " << b << endl;
   //mySwap(a, c) //错误，推导不出一致的T类型
}

//模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
   cout << "func调用" << endl;
}

void test02()
{
   //func(); 错误，模板不能独立使用
   func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用
}


int main()
{
   test01();
   test02();
   //system("pause");
   return 0;
}
