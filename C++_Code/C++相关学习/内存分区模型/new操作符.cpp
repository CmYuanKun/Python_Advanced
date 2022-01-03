#include <iostream>
using namespace std;


int * func()
{

    int *a  = new int(10);

    return a;

}


int main()
{
    int * p = func();


    cout << *p << endl;

    cout << *p << endl;

    //利用delete释放堆区空间
    delete p;
    p = NULL;

    //cout << *p << endl;  释放的空间不能被访问
    return 0;
}