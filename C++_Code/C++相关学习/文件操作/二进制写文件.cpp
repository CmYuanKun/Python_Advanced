#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class Person
{

public:
    char m_Name[64];
    int m_Age;

};

//������д�ļ� 


void test01(){

    //������������󼰴��ļ�
    ofstream ofs("test.txt", ios::out | ios::binary);

    Person p = {"����", 18};

    //д�ļ�
    ofs.write((const char *)&p, sizeof(p));

    //�ر��ļ�
    ofs.close();


}




int main(){

    test01();
    return 0;
}