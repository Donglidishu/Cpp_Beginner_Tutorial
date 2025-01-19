#include <iostream>
#include <string>
using namespace std;

bool testPalindrome(string str)
{
    string temp;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        temp += str[i];
    }

    if (temp == str)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str;
    cout << "请输入一段字符串: ";
    cin >> str;
    bool ret = testPalindrome(str);
    if (ret == 1)
    {
        cout << "是回文" << endl;
    }
    else if (ret == 0)
    {
        cout << "不是回文" << endl;
    }
    return 0;
}