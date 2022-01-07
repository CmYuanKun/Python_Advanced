#include <iostream>
#include <string>

using namespace std;

void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
    cout << "调用的模板" << endl;
}

template<typename T>
void myPrint(T a, T b, T c)
{
    cout << "调用的模板" << endl;
}


void test01()
{
    int a = 1;
    int b = 2;
    myPrint(a, b); 
    myPrint<>(a, b);

    int c = 30;
    myPrint<>(a, b, c); //函数模板可以发生重载

    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2); //调用函数模板

}



int main()
{
   test01();
   //system("pause");
   return 0;
}
