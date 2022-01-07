#include<iostream>

using namespace std;

//引用必须初始化
//引用在初始化后，不可以改变


int main()
{

    int a = 10;
    int b = 10;

    
    int &c = a; //一但初始化后，就不可以被更改

    c = b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;

}