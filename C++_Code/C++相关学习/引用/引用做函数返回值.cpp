#include<iostream>
using namespace std;

//���ؾֲ���������
// int& test01()
// {
//     int a = 10;  //�ֲ�����
//     return a;
// }

//���ؾ�̬��������
int& test02()
{
    static int a = 10;
    return a;

}


int main()
{

    //���ܷ��ؾֲ�����������
    // int& rdf = test01();
    // cout << "rdf = " << rdf << "rdf = " << rdf << endl;

    // �����������ֵ����ô���뷵������
    int& rdf1 = test02();

    cout << "rdf1 = " << rdf1 << " rdf1 = " << rdf1 << endl;
    test02() = 100;

    cout << "rdf1 = " << rdf1 << " rdf1 = " << rdf1 << endl;


    return 0;
}