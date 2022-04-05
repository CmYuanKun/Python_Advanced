#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
}


void test02()
{
    vector<int> v1;
    vector<int> v2;

    for(int i = 0; i< 10 ; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;

    //取两个里较小的目标开辟空间
    vTarget.resize(min(v1.size(), v2.size()));

    //返回目标容器的最后一个元素的迭代器

    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
}





int main()
{
    //test01();
    test02();
    //system("pause");
    return 0;
}
