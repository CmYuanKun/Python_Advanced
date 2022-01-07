#include <iostream>
#include <string>

using namespace std;

//普通函数
int myAdd01(int a, int b)
{
    return a + b;
}


//函数模板
template<class T>
T myAdd02(T a, T b)
{
    return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换，
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a, c) << endl;  //正常，

    //myAdd02(a, c); 报错，使用自动类型推导时，不会发生隐式类型转换

    myAdd02<int>(a, c); // 正确，如果用显示指定类型，可以发生隐式类型转换
    cout << myAdd02<int>(a, c) << endl;
}



int main()
{
   test01();
   //system("pause");
   return 0;
}
