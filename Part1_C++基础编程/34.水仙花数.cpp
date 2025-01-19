#include <iostream>
using namespace std;
int main()
{
    // 求出所有的水仙花数（三位数，每个位置上的数的三次幂的和还等于水仙花数本身
    int num = 100;
    do
    {
        int a = num / 100;     // 获取百位数字
        int b = num / 10 % 10; // 获取十位数字
        int c = num % 10;      // 获取个位数字

        if (num == a * a * a + b * b * b + c * c * c)
        {
            cout << num << endl;
        }

        num++;
    } while (num < 1000);

    return 0;
}