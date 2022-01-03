#include <iostream>
#include <string>
using namespace std;

//常函数：
//成员函数后加const后称为函数为常函数
//常函数内不可以修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改

//常对象：
//声明对象前加const称该对象为常对象
//常对象只能调用常函数


class Person
{
private:
    /* data */
public:
    Person(){
        
        m_A = 0;
        m_B = 0;
    };

    void showPersion() const{

        this ->m_B = 10;

    }


    void MyFunc() const{

    }

    int m_A;
    mutable int m_B;  //可修改， 可变的
};


void test01()
{
    const Person person;  //常对象
    cout << person.m_A << endl;

    //person.m_A = 100;  //常对象不能修改成员变量的值，但是可以访问

    person.m_B = 100;  //但是常对象可以修改mutable修饰的成员变量

    //常对象访问成员函数
    //person.Myfunc(); //常对象不能调用const的函数
}



int main(){
    test01();

    return 0;

}















