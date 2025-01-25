#include <iostream>
using namespace std;

//  string& operator+=(const char str);                   //重载+=操作符
//  string& operator+=(const char c);                         //重载+=操作符
//  string& operator+=(const string& str);                //重载+=操作符
//  string& append(const char s);                                //把字符串s连接到当前字符串结尾
//  string& append(const char s, int n);                 //把字符串s的前n个字符连接到当前字符串结尾
//  string& append(const string &s);                           //同operator+=(const string& str)
//  string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾

// 赋值
void test01()
{
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hello c++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello c++", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(5, 'x');
    cout << "str7 = " << str7 << endl;
}

int main()
{

    test01();

    return 0;
}
