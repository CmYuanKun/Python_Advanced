#include <iostream>
#include <string>
using namespace std;

//��������
//��Ա�������const���Ϊ����Ϊ������
//�������ڲ������޸ĳ�Ա����
//��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

//������
//��������ǰ��const�Ƹö���Ϊ������
//������ֻ�ܵ��ó�����


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
    mutable int m_B;  //���޸ģ� �ɱ��
};


void test01()
{
    const Person person;  //������
    cout << person.m_A << endl;

    //person.m_A = 100;  //���������޸ĳ�Ա������ֵ�����ǿ��Է���

    person.m_B = 100;  //���ǳ���������޸�mutable���εĳ�Ա����

    //��������ʳ�Ա����
    //person.Myfunc(); //�������ܵ���const�ĺ���
}



int main(){
    test01();

    return 0;

}















