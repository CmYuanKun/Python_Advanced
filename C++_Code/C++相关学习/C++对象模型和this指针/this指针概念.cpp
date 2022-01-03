#include <iostream>
#include <string>
using namespace std;

//每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
//this指针的用途： this指针指向被调用的成员函数所属的对象
//当形参和成员变量同名时，可用this指针来区分
//在类的非静态成员函数中返回对象本身，可使用了return *this

class Person{
public:

    Person(int age){
        cout << "构造函数入参 age = " << age << endl;
        //当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    }


    Person&  PersonAddPersion(Person p){
        this->age += p.age;
        //返回对象本身
        return *this;
    }

    int age = 1;

};



void test01(){

    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);

    p2.PersonAddPersion(p1).PersonAddPersion(p1).PersonAddPersion(p1);

    cout << "p2.age = " << p2.age << endl;

}



int main(){

    test01();

    return 0;
}