#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//vector����Ƕ������
void test01()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for(int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v1.push_back(i + 2);
        v1.push_back(i + 3);
        v1.push_back(i + 4);
    }

    //������Ԫ�ز��뵽vector v��

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit!= (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }

}

//�Զ�����������
class Person
{
public:

    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }

    string mName;
    int mAge;
};


//��Ŷ���
void test02()
{
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name:" << (*it).mName <<" Age:" << (*it).mAge << endl;
    }
}

//�Ŷ���ָ��

void test03()
{
    vector<Person*> v;

    //��������
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        // Person *p = *it;
        // cout << "Name:" << p->mName <<" Age:" << p->mAge << endl;
        cout << "Name:" << (**it).mName <<" Age:" << (**it).mAge << endl;
    }

}


//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ���������
void MyPrint(int val)
{
    cout << val << endl;
}

void test04()
{
    //����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ���������

    vector<int> v;

    //�������з�����
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);


    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    //��һ�ֱ�����ʽ

    while(pBegin != pEnd)
    {
        cout << *pBegin << endl;
        pBegin++;
    }
    cout << endl;

    //�ڶ��ֱ�����ʽ
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
    {
        cout << *it<< endl;
    }
    cout << endl;

    //�����ַ�ʽ

    //ʹ��STL�ṩ��׼�����㷨 ͷ�ļ� algorithm

    for_each(v.begin(), v.end(), MyPrint);

}




int main()
{
    test01();
    test02();
    test03();
    test04();
   //system("pause");
    return 0;
}