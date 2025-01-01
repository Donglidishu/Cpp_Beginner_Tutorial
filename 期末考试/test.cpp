#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello, world!";

    size_t pos = str.find('w'); // 查找字符 'w'

    if (pos != string::npos)
    {
        cout << "'w' found at position: " << pos << endl;
    }
    else
    {
        cout << "'w' not found." << endl;
    }

    return 0;
}