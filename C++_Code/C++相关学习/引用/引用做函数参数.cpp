#include<iostream>
using namespace std;

//ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������


//ֵ����

void mySwap01(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//��ַ����
void mySwap02(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//���ô���
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