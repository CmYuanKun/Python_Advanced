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

//二进制写文件 


void test01(){

    //创建输出流对象及打开文件
    ofstream ofs("test.txt", ios::out | ios::binary);

    Person p = {"张三", 18};

    //写文件
    ofs.write((const char *)&p, sizeof(p));

    //关闭文件
    ofs.close();


}




int main(){

    test01();
    return 0;
}