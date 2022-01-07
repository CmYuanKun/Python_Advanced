#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//deque构造
void test01()
{
    deque<int> d1; //无参构造函数
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int>d3(10, 100);
    printDeque(d3);

    deque<int>d4 = d3;
    printDeque(d4);

}

void test02()
{
    deque<int> d1;
    for(int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2;
    d2 = d1;
    printDeque(d2);


    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int> d4;

    d4.assign(10, 100);
    printDeque(d4);

}


void test03()
{
    deque<int> d1;
    for(int i = 0; i< 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);


    if(d1.empty())
    {
        cout <<"d1为空!" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        //统计大小
        cout << "d1的大小为：" << d1.size() << endl;
    }
    //重新指定大小

    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);

}


//deque插入和删除

void test04()
{
    deque<int> d;
    //尾插
    d.push_back(10);
    d.push_back(20);
    //头插
    d.push_front(30);
    d.push_front(200);

    printDeque(d);

    //尾删
    d.pop_back();
    //头删
    d.pop_front();
    printDeque(d);


    d.insert(d.begin(), 1000);
    printDeque(d);

    d.insert(d.begin() + 2, 1000);
    printDeque(d);

    d.insert(d.begin(), 2, 1000);
    printDeque(d);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin(), d2.begin(), d2.end());
    printDeque(d);

    // //删除
    // d.erase(d.begin(), d.end());
    // printDeque(d);

    // //清空
    // d.clear();
    // printDeque(d);

    for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;



    for(int i =0; i< d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;


    cout << "front : " << d.front() << endl;
    cout << "back : " << d.back() << endl;

    //排序
    sort(d.begin(), d.end());
    printDeque(d);

}




int main()
{
    //test01();
    //test02();
    //test03();
    test04();
    //system("pause");
    return 0;
}
