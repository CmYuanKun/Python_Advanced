#include <iostream>
#include <string>

using namespace std;

// ���ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
// ֻ�зǾ�̬��Ա������������Ķ�����
class Person {
public:
    Person(){
        m_A = 0;
    }

    //�Ǿ�̬������Առ����ռ�
    int m_A;

    //��̬��Ա������ռ����ռ�
    static int m_B;


    //����Ҳ��ռ����ռ䣬���к�������һ������ʵ��
    void func(){

        cout << "m_A : " << this->m_B << endl;
    }

    //��̬��Ա����Ҳ��ռ����ռ�
    static void sfunc(){

    }

};



int main(){
    
    Person person;

    cout << "Person���С: " << sizeof(Person) << endl;

    system("pause");


    return 0;
}

