#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//�ַ���ƴ��
void test06()
{
    string str1 = "��";
    str1 += "������Ϸ";

    cout << "str1 = " << str1<< endl;

    str1 += ":";

    cout << "str1 = " << str1 << endl;

    string str2 = "LOL DNF";
    str1 += str2;

    cout << "str1 = "  << str1 << endl;

    string str3 = "I";
    str3.append("love");
    str3.append("game abcde", 4);
    str3.append(str2, 4, 3); // ���±�4λ�ÿ�ʼ ����ȡ3���ַ���ƴ�ӵ��ַ���ĩβ
    cout << "str3 = "  << str3 << endl;


}



//�ַ�������
void test5()
{
    //����
    string str1 = "abcdefrgjkh";
    int pos = str1.find("de");

    if(pos == -1)
    {
        cout << "δ�ҵ�" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }

    pos  = str1.rfind("de");

    cout << "++++pos = " << pos << endl;
}

//find�����Ǵ�������rfind��������
//find�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1
//replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���
void test02()
{
    //�滻
    string str1 = "abcdefgde";
    str1.replace(1, 3, "111");
    cout << "str1 = " << str1 << endl;
}

//string �ַ����Ƚ�

void test03()
{
    string s1 = "hello4";
    string s2 = "hello1";

    int ret  = s1.compare(s2);

    if(ret == 0)
    {
        cout << "s1 ���� s2" << endl;
    }
    else if(ret > 0)
    {
        cout << "s1 > s2" << endl;
    }else
    {
        cout << "s1 < s3"<< endl;
    }

}

//string�ַ�����ȡ

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


//string���캯��
void test01()
{
    string s1; //�������ַ����������޲ι��캯��

    cout << "str1 = " << s1 << endl;

    const char * str = "hello world";
    string s2(str); //��c_stringת����string

    cout << "str2 = " << s2 << endl;

    string s3(s2);  //���ÿ������캯��

    cout << "str3 = " << s3 << endl;

    string s4(10,'a');

    cout << "str4 = " << s4 << endl;


}

//string �����ɾ��
void test05()
{
    string str = "hello";
    str.insert(1, "1111");

    cout << str << endl;

    str.insert(1, 2, 'm');
    cout << str << endl;

    str.erase(1, 3); // ��1��λ�ÿ�ʼ3���ַ�
    cout << str << endl;
}


//string�Ӵ�
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
