#include<iostream>

using namespace std;

//���ñ����ʼ��
//�����ڳ�ʼ���󣬲����Ըı�


int main()
{

    int a = 10;
    int b = 10;

    
    int &c = a; //һ����ʼ���󣬾Ͳ����Ա�����

    c = b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;

}