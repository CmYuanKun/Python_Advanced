#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


void printList(const list<int> & L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int> L2(L1.begin(), L1.end());
    printList(L2);

    list<int> L3(L2);
    printList(L3);

    list<int> L4(10, 1000);
    printList(L4);

}


//��ֵ�ͽ���
void test02()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    //��ֵ
    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);


    list<int> L4;
    L4.assign(10, 88);
    printList(L4);


    list<int> L5;
    L5.assign(10, 100);

    cout << "����ǰ�� " << endl;
	printList(L4);
	printList(L5);

	cout << endl;

	L4.swap(L5);

	cout << "������ " << endl;
	printList(L4);
	printList(L5);


    if(!L5.empty())
    {
        cout << "L5Ϊ��" << endl;
    }
    else
    {
        cout <<"L5��Ϊ��" << endl;
        cout << "L5�Ĵ�СΪ��" << L5.size() << endl;
    }

    //����ָ����С
    L5.resize(10);
    printList(L5);

    L5.resize(2);
    printList(L5);

}

void test03()
{
    list <int> L;
    //β��
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    //ͷ��
    L.push_front(100);
    L.push_front(300);

    printList(L);
    //βɾ

    L.pop_back();
    printList(L);


    //����
    list<int>::iterator it = L.begin();
    L.insert(++it, 1000);
    printList(L);

    //���
    // L.clear();
    // printList(L);


    cout << L.front() << endl;
    cout << L.back() << endl;

    //list<int>::iterator it = L1.begin();
}


bool myCompare(int val1 , int val2)
{
	return val1 > val2;
}



//��ת������

void test06()
{
    list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);



    //��ת������Ԫ��
    L.reverse();
    printList(L);

    //����
    L.sort();
    printList(L);

    L.sort(myCompare);
    printList(L);

}


int main()
{
    //test01();   
    //test02(); 
    //test03();
    test06();
    //system("pause");
    return 0;
}
