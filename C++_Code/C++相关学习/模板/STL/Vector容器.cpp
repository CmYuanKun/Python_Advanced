#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector���ݽṹ������ṹ����,Ҳ��Ϊ��������

//��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ

void printVector(vector<int> & v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}

void test01()
{
    vector <int> v1; //�޲ι���

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    } 
    printVector(v1);
    cout << "v1 = " <<&v1 <<endl;

    //��v[begin(), end())�����е�Ԫ�ؿ���������
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);
    cout << "v2 = " << &v2 <<endl;

    vector<int> v3(10, 100);
    printVector(v3);
    cout << "v3 = " << &v3 <<endl;

    //��������
    vector<int> v4(v3);
    printVector(v4);
    cout << "v4 = " << &v4 <<endl;
}


//vector��ֵ����

void test02()
{
    vector<int> v1; //�޲ι���
    for(int i = 0; i< 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);


}


//vector�����ʹ�С
void test03()
{
    vector<int> v1;
    for(int i = 0; i< 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty())
    {
        cout << "v1Ϊ��" <<endl;
    }
    else
    {
        cout << "v1��Ϊ��" << endl;
        cout << "v1������ = "<< v1.capacity() <<endl;
        cout << "v1�Ĵ�С = "<< v1.size() <<endl;
    }

    v1.resize(15, 39); //����ָ����������
    printVector(v1);

    v1.resize(5); //����ָ����������
    printVector(v1);

    v1.resize(10); //����ָ����������
    printVector(v1);

}

//vector�����ɾ��
void test04()
{
    vector<int> v1;
    //β��
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    printVector(v1);

    //βɾ
    v1.pop_back();
    printVector(v1);

    //����
    v1.insert(v1.begin(), 100);
    printVector(v1);


    //ָ��λ�ò���
    v1.insert(v1.begin(), 2, 14);
    printVector(v1);


    //ɾ��
    v1.erase(v1.begin());
    printVector(v1);

    //ָ��ɾ��
    v1.erase(v1.begin() + 1, v1.end() - 1);
    printVector(v1);

    //�������

    v1.clear();
    printVector(v1);
}

//vector���ݴ�ȡ

void test05()
{
    vector<int> v1;

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // for(int i = 0 ; i < v1.size(); i++)
    // {
    //     cout << v1[i] << endl;
    // }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << endl;
    }

    cout << "v1�ĵ�һ��Ԫ��Ϊ��" << v1.front() << endl;
    cout << "v1�����һ��Ԫ��Ϊ��" << v1.back() << endl;

}

void test06()
{
    vector<int> v1;

    for (int i =0; i< 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;

    for (int i =0; i< 10; i++)
    {
        v2.push_back(i);
    }
    printVector(v2);

    //��������

    cout << "������" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);


}

void test07()
{
    vector<int> v;

    for(int i =0; i < 10000; i++)
    {   
        v.push_back(i);
    }

    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;

    v.resize(3);

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

    //�����ڴ�
    vector<int>(v).swap(v); //��������

    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;

}

//Ԥ���ռ�

void test08()
{
    vector<int> v;

    //Ԥ���ռ�
    v.reserve(100000);

    int num = 0;
    int *p = NULL;

    for( int i = 0; i<100000; i++)
    {   
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "num:" <<num << endl;

}



int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();
    //system("pause");
    return 0;
}
