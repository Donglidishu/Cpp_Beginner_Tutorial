#include <cctype> // 提供 islower, isupper
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello, World!";

    for (char &ch : str)
    {
        if (islower(ch))
        {
            ch = toupper(ch); // 小写转大写
        }
        else if (isupper(ch))
        {
            ch = tolower(ch); // 大写转小写
        }
    }

    cout << "Toggle case: " << str << endl;

    return 0;
}