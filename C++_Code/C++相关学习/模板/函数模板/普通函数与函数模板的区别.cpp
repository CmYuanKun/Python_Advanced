#include <iostream>
#include <string>

using namespace std;

//��ͨ����
int myAdd01(int a, int b)
{
    return a + b;
}


//����ģ��
template<class T>
T myAdd02(T a, T b)
{
    return a + b;
}

//ʹ�ú���ģ��ʱ��������Զ������Ƶ������ᷢ���Զ�����ת����
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a, c) << endl;  //������

    //myAdd02(a, c); ����ʹ���Զ������Ƶ�ʱ�����ᷢ����ʽ����ת��

    myAdd02<int>(a, c); // ��ȷ���������ʾָ�����ͣ����Է�����ʽ����ת��
    cout << myAdd02<int>(a, c) << endl;
}



int main()
{
   test01();
   //system("pause");
   return 0;
}
