#include <cctype> // 提供 toupper
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello, World!";

    for (char &ch : str)
    {
        ch = toupper(ch); // 将每个字符转换为大写
    }

    cout << "Uppercase: " << str << endl;

    return 0;
}