#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    // 先运行do内的操作，在经过while判断决定是否继续循环
    do
    {
        cout << num << endl;
        num++;

    } while (num < 10);

    return 0;
}