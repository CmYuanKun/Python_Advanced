#include <iostream>
#include <fstream>

using namespace std;

//文件以文本的ASCII码形式存储在计算机中

void test01(){

    //实例化文件输出流
    ofstream ofs;


    ofs.open("test.txt", ios::out);

    ofs << "姓名: 张三"<< endl;
    ofs << "性别:  男" << endl;
    ofs << "年龄: 18" << endl;
    
    ofs.close();
    return;
}


int main(){

    test01();

    return 0;
}