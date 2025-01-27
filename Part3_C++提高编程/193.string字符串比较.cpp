#include <iostream>
#include <string>
using namespace std;

// 字符串比较是按字符串的ASCII码进行比较

void test01()
{
    string str1 = "hello";
    string str2 = "world";
    if (str1.compare(str2) == 0)
    {
        cout << "str1 = str2" << endl;
    }
    else if (str1.compare(str2) == 1)
    {
        cout << "str1 > str2" << endl;
    }
    else
    {
        cout << "str1 < str2" << endl;
    }
}

int main()
{
    test01();
    return 0;
}