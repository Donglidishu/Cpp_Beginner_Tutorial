#include <cctype> // 提供 tolower
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello, World!";

    for (char &ch : str)
    {
        ch = tolower(ch); // 将每个字符转换为小写
    }

    cout << "Lowercase: " << str << endl;

    return 0;
}