#include<iostream>
#include<string>

using namespace std;

//代码区： 
//存放CPU执行的机器指令，
//代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
//代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令


//全局区：
//全局变量和静态变量存放在此
//全局区还包含了常量区，字符串常量和其他常量也存放在此


//全局变量
int g_a = 10;
int g_b = 10;

//全局常量

const int c_g_a = 10;
const int c_g_b = 10;


int main(){

    //局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量a地址为:  "<< &a <<endl;
    cout << "局部变量b地址为:  "<< &b <<endl;

    cout << "全局变量g_a地址为:  "<< &g_a <<endl;
    cout << "全局变量g_b地址为:  "<< &g_b <<endl;

    //静态变量

    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量s_a地址为:  "<< &s_a <<endl;
    cout << "静态变量s_b地址为:  "<< &s_b <<endl;

    cout << "字符串常量地址为: " << &"hello world" << endl;
    cout << "字符串常量地址为: " << &"hello world1" << endl;

    cout << "全局常量c_g_a地址为: " << &"c_g_a" << endl;
    cout << "全局常量c_g_b地址为: " << &"c_g_b" << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;

    cout << "局部常量c_1_a地址为: " << &"c_1_a" << endl;
    cout << "局部常量c_1_b地址为: " << &"c_1_b" << endl;

    return 0;
}



