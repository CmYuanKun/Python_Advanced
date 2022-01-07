#include<iostream>
using namespace std;

//返回局部变量引用
// int& test01()
// {
//     int a = 10;  //局部变量
//     return a;
// }

//返回静态变量引用
int& test02()
{
    static int a = 10;
    return a;

}


int main()
{

    //不能返回局部变量的引用
    // int& rdf = test01();
    // cout << "rdf = " << rdf << "rdf = " << rdf << endl;

    // 如果函数做左值，那么必须返回引用
    int& rdf1 = test02();

    cout << "rdf1 = " << rdf1 << " rdf1 = " << rdf1 << endl;
    test02() = 100;

    cout << "rdf1 = " << rdf1 << " rdf1 = " << rdf1 << endl;


    return 0;
}