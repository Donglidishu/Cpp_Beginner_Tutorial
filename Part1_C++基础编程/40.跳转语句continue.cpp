#include <iostream>
using namespace std;
int main()
{
    // continue语句：在循环中遇到continue，跳过循环余下的未执行语句，直接继续执行下一次循环
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0) // 只输出奇数
        {
            continue;
        }
        cout << i << endl;
    }

    return 0;
}