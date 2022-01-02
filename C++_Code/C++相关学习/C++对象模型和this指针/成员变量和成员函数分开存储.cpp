#include <iostream>
#include <string>

using namespace std;

// 类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上
class Person {
public:
    Person(){
        m_A = 0;
    }

    //非静态变量成员占对象空间
    int m_A;

    //静态成员变量不占对象空间
    static int m_B;


    //函数也不占对象空间，所有函数共享一个函数实例
    void func(){

        cout << "m_A : " << this->m_B << endl;
    }

    //静态成员函数也不占对象空间
    static void sfunc(){

    }

};



int main(){
    
    Person person;

    cout << "Person类大小: " << sizeof(Person) << endl;

    system("pause");


    return 0;
}

