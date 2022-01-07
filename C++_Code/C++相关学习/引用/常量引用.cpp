#include<iostream>
using namespace std;


//引用的本质在c++内部实现是一个指针常量.

//如果是引用，转换为 int* const ref = &a;
void func(int& ref)
{
    ref = 100;

}


int main()
{
    int a = 100;


    int& ref = a;

    ref  = 20;

    cout << "a:" << a << endl;
	cout << "ref: " << ref << endl;

    func(a);
    return 0;
    
}