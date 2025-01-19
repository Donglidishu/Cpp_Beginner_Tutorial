#include <iostream>
using namespace std;

// 递归函数计算最大公约数
int gcd(int x, int y)
{
    if (y == 0)
    { // 基础情况：当 y 为 0 时
        return x;
    }
    return gcd(y, x % y); // 递归调用
}

int main()
{
    int x, y;
    cout << "请输入两个整数 (x > y): ";
    cin >> x >> y;

    // 确保 x > y
    if (x < y)
    {
        swap(x, y);
    }

    int result = gcd(x, y);
    cout << x << " 和 " << y << " 的最大公约数是: " << result << endl;

    return 0;
}