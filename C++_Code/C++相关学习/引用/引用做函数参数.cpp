#include<iostream>
using namespace std;

//通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单


//值传递

void mySwap01(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//地址传递
void mySwap02(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//引用传递
void mySwap03( int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;

}   


int main()
{

    int a = 10;
    int b = 12;

    mySwap01(a, b);
    cout <<"a = "<< a <<" b = "<< b << endl;

    mySwap02(&a, &b);
    cout <<"a = "<< a <<" b = "<< b << endl;


    mySwap03(a, b);
    cout <<"a = "<< a <<" b = "<< b << endl;

    return 0;
}