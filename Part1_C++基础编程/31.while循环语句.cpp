#include <iostream>
using namespace std;
int main()
{
    // 用while输出0~9十个数字
    int num = 0;
    while (num < 10) // 括号内为判断条件，应当避免出现死循环，如填入1（真）
    {
        cout << num << endl;
        num++;
    }

    return 0;
}