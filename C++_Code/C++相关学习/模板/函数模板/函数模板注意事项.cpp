#include <iostream>
#include <string>

using namespace std;

//����ģ���ṩͨ�õĽ�������
template<class T>
void mySwap(T &a, T& b)
{
   T temp = a;
   a = b;
   b = temp;
}

//�Զ��������Ƶ��������Ƶ���һ�µ���������T,����ʹ��
void test01()
{
   int a = 10;
   int b = 20;
   char c = 'c';

   mySwap(a, b);
   cout << "a = " << a << " b= " << b << endl;
   //mySwap(a, c) //�����Ƶ�����һ�µ�T����
}

//ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
   cout << "func����" << endl;
}

void test02()
{
   //func(); ����ģ�岻�ܶ���ʹ��
   func<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ��
}


int main()
{
   test01();
   test02();
   //system("pause");
   return 0;
}
