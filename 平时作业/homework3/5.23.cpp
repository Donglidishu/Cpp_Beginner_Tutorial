#include <iostream>
using namespace std;

int main()
{
    int n = 4; // 菱形的中间行数

    // 打印菱形的上半部分
    for (int i = 0; i <= n; ++i)
    {
        // 打印空格
        for (int j = 0; j < n - i; ++j)
        {
            cout << " ";
        }
        // 打印星号
        for (int k = 0; k < 2 * i + 1; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 打印菱形的下半部分
    for (int i = n - 1; i >= 0; --i)
    {
        // 打印空格
        for (int j = 0; j < n - i; ++j)
        {
            cout << " ";
        }
        // 打印星号
        for (int k = 0; k < 2 * i + 1; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}