#include <iostream>
#include <string>
using namespace std;

//ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����
//thisָ�����;�� thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
//���βκͳ�Ա����ͬ��ʱ������thisָ��������
//����ķǾ�̬��Ա�����з��ض�������ʹ����return *this

class Person{
public:

    Person(int age){
        cout << "���캯����� age = " << age << endl;
        //���βκͳ�Ա����ͬ��ʱ������thisָ��������
        this->age = age;
    }


    Person&  PersonAddPersion(Person p){
        this->age += p.age;
        //���ض�����
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