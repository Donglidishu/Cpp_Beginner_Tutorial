#include <iostream>
#include <string>
using namespace std;

// string字符存取
void test01()
{
    string str = "hello world";

    // 通过[]访问单个字符
    for (int i = 0; i < str.size(); i++) // size()可以返回字符串长度
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // 通过at访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 字符修改
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;
}
int main()
{
    test01();
    return 0;
}
