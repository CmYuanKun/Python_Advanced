#include <iostream>
#include <string>

using namespace std;

void myPrint(int a, int b)
{
    cout << "���õ���ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
    cout << "���õ�ģ��" << endl;
}

template<typename T>
void myPrint(T a, T b, T c)
{
    cout << "���õ�ģ��" << endl;
}


void test01()
{
    int a = 1;
    int b = 2;
    myPrint(a, b); 
    myPrint<>(a, b);

    int c = 30;
    myPrint<>(a, b, c); //����ģ����Է�������

    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2); //���ú���ģ��

}



int main()
{
   test01();
   //system("pause");
   return 0;
}
