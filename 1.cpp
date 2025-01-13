#include <cstring>
#include <iostream>

using namespace std;

void func(char str[], char ch)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ch)
        {
            for (int j = i; j < len - 1; j++)
            {
                str[i] = str[i + 1];
            }
            len--;
            i--;
        }
    }
    cout << str << endl;
}

int main()
{
    char str[80];
    char ch;
    cout << "输入字符串" << endl;
    cin >> str;
    cout << "输入ch" << endl;
    cin >> ch;
    func(str, ch);
    return 0;
}