#include <iostream>
# include <string>

using namespace std;


//C++�п�ָ��Ҳ�ǿɵ��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��



//��ָ����ʳ�Ա����

class Persion{

public:
    void showClassName(){
        cout << "����Person��!" << endl;
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

