#include <iostream>
# include <string>

using namespace std;


//C++中空指针也是可调用成员函数的，但是也要注意有没有用到this指针



//空指针访问成员函数

class Persion{

public:
    void showClassName(){
        cout << "我是Person类!" << endl;
    }

    void showPerson(){

        if (this == NULL){

            return;
        }
        cout <<"m_age =" << m_Age << endl;
    }


public:
    int m_Age;
};


void test01(){

    Persion * p1 = NULL;

    p1 ->showClassName();
    p1 -> showPerson();


    return;
}




int main(){

    test01();

    return 0;
}

