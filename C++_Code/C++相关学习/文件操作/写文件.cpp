#include <iostream>
#include <fstream>

using namespace std;

//�ļ����ı���ASCII����ʽ�洢�ڼ������

void test01(){

    //ʵ�����ļ������
    ofstream ofs;


    ofs.open("test.txt", ios::out);

    ofs << "����: ����"<< endl;
    ofs << "�Ա�:  ��" << endl;
    ofs << "����: 18" << endl;
    
    ofs.close();
    return;
}


int main(){

    test01();

    return 0;
}