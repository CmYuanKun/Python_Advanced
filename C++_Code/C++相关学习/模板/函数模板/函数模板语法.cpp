#include <iostream>
#include <string>

using namespace std;

//交换整形函数
void swapInt(int& a, int& b)
{
    int temp = a;
    a = b;
    b =temp;

}

//交换浮点数函数
void swapDou(double& a, double& b)
{
    double temp = a;
    a = b;
    b =temp;
}

//利用模板提供通用交换函数
template <typename T>
void swapint(T& a, T& b)
{
    T temp = a;
    a = b;
    b =temp;
}


void test01()
{
    int a = 10;
    int b = 20;

    //swapInt(a, b);
    swapint(a, b);
    
    cout << "a = " << a << " b =" << b << endl;

    double a1 = 10.11;
    double b1 = 20.22;

    //swapDou(a1, b1);
    swapint(a1, b1);
    cout << "a1 = " << a1 << " b1 =" << b1 << endl;


}


int main()
{
   test01();
   system("pause");
   return 0;
}
