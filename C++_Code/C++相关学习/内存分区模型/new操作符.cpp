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

    //����delete�ͷŶ����ռ�
    delete p;
    p = NULL;

    //cout << *p << endl;  �ͷŵĿռ䲻�ܱ�����
    return 0;
}