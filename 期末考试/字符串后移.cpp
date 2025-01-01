#include <iostream>
#include <string>
using namespace std;

void shiftCharacters(string &str, int shift)
{
    for (char &ch : str)
    {
        if (isalpha(ch))
        {                                         // 只处理字母
            char base = islower(ch) ? 'a' : 'A';  // 判断大小写
            ch = (ch - base + shift) % 26 + base; // 循环位移
        }
    }
}

int main()
{
    string str = "Hello, World!";
    int shift = 3;

    shiftCharacters(str, shift);

    cout << "Shifted string: " << str << endl;

    return 0;
}