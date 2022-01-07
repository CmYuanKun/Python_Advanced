#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector数据结构和数组结构相似,也成为单端数组

//不同之处在于数组是静态空间，而vector可以动态扩展

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
    vector <int> v1; //无参构造

    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    } 
    printVector(v1);
    cout << "v1 = " <<&v1 <<endl;

    //将v[begin(), end())区间中的元素拷贝给本身
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);
    cout << "v2 = " << &v2 <<endl;

    vector<int> v3(10, 100);
    printVector(v3);
    cout << "v3 = " << &v3 <<endl;

    //拷贝构造
    vector<int> v4(v3);
    printVector(v4);
    cout << "v4 = " << &v4 <<endl;
}


//vector赋值操作

void test02()
{
    vector<int> v1; //无参构造
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


//vector容量和大小
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
        cout << "v1为空" <<endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量 = "<< v1.capacity() <<endl;
        cout << "v1的大小 = "<< v1.size() <<endl;
    }

    v1.resize(15, 39); //重新指定容器长度
    printVector(v1);

    v1.resize(5); //重新指定容器长度
    printVector(v1);

    v1.resize(10); //重新指定容器长度
    printVector(v1);

}

//vector插入和删除
void test04()
{
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    printVector(v1);

    //尾删
    v1.pop_back();
    printVector(v1);

    //插入
    v1.insert(v1.begin(), 100);
    printVector(v1);


    //指定位置插入
    v1.insert(v1.begin(), 2, 14);
    printVector(v1);


    //删除
    v1.erase(v1.begin());
    printVector(v1);

    //指定删除
    v1.erase(v1.begin() + 1, v1.end() - 1);
    printVector(v1);

    //清空数据

    v1.clear();
    printVector(v1);
}

//vector数据存取

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

    cout << "v1的第一个元素为：" << v1.front() << endl;
    cout << "v1的最后一个元素为：" << v1.back() << endl;

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

    //互换容器

    cout << "互换后" << endl;
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

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    v.resize(3);

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

    //收缩内存
    vector<int>(v).swap(v); //匿名对象

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

}

//预留空间

void test08()
{
    vector<int> v;

    //预留空间
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
