#include<iostream>
using namespace std;


//���õı�����c++�ڲ�ʵ����һ��ָ�볣��.

//��������ã�ת��Ϊ int* const ref = &a;
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