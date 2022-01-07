#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//字符串拼接
void test06()
{
    string str1 = "我";
    str1 += "爱玩游戏";

    cout << "str1 = " << str1<< endl;

    str1 += ":";

    cout << "str1 = " << str1 << endl;

    string str2 = "LOL DNF";
    str1 += str2;

    cout << "str1 = "  << str1 << endl;

    string str3 = "I";
    str3.append("love");
    str3.append("game abcde", 4);
    str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
    cout << "str3 = "  << str3 << endl;


}



//字符串查找
void test5()
{
    //查找
    string str1 = "abcdefrgjkh";
    int pos = str1.find("de");

    if(pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }

    pos  = str1.rfind("de");

    cout << "++++pos = " << pos << endl;
}

//find查找是从左往后，rfind从右往左
//find找到字符串后返回查找的第一个字符位置，找不到返回-1
//replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
void test02()
{
    //替换
    string str1 = "abcdefgde";
    str1.replace(1, 3, "111");
    cout << "str1 = " << str1 << endl;
}

//string 字符串比较

void test03()
{
    string s1 = "hello4";
    string s2 = "hello1";

    int ret  = s1.compare(s2);

    if(ret == 0)
    {
        cout << "s1 等于 s2" << endl;
    }
    else if(ret > 0)
    {
        cout << "s1 > s2" << endl;
    }else
    {
        cout << "s1 < s3"<< endl;
    }

}

//string字符串存取

void test04()
{
    string str = "hello world";

    for(int i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl;
    }
    
    for(int i = 0; i < str.size(); i++)
    {
        cout <<str.at(i) << endl;
    }
}


//string构造函数
void test01()
{
    string s1; //创建空字符串，调用无参构造函数

    cout << "str1 = " << s1 << endl;

    const char * str = "hello world";
    string s2(str); //把c_string转换成string

    cout << "str2 = " << s2 << endl;

    string s3(s2);  //调用拷贝构造函数

    cout << "str3 = " << s3 << endl;

    string s4(10,'a');

    cout << "str4 = " << s4 << endl;


}

//string 插入和删除
void test05()
{
    string str = "hello";
    str.insert(1, "1111");

    cout << str << endl;

    str.insert(1, 2, 'm');
    cout << str << endl;

    str.erase(1, 3); // 从1号位置开始3个字符
    cout << str << endl;
}


//string子串
void test07()
{
    string str = "abcdef";
    string substr = str.substr(1, 3);

    cout <<"subStr = " <<str << endl; 

    string email = "hello@sina.com";

    int pos = email.find("@");

    string username = email.substr(0, pos);
    cout << "username: " << username << endl;

}



int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    //test05();
    //test06();
    test07();
    //system("pause");
    return 0;
}
