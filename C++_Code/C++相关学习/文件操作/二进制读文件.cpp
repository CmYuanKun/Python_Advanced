#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class Persion
{

public:
    char m_Name[64];
    int m_Age;
};



void test01(){

    ifstream ifs("test.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
    }

    Persion p;

    ifs.read((char *)&p, sizeof(p));

    cout << "����: " << p.m_Name <<"����: " << p.m_Age <<endl;
}




int main(){

    test01();

    return 0;
}