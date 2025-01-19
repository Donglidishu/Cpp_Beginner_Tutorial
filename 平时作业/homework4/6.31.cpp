#include <iostream>
using namespace std;

// 使用欧几里得算法计算最大公约数
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int num1, num2;
    cout << "输入两个整数：";
    cin >> num1 >> num2;

    cout << "最大公约数是：" << gcd(num1, num2) << endl;

    return 0;
}