#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int minNum = (a < b) ? a : b;
    for (int i = minNum; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    int a, b;
    cout << "请输入两个数a b: ";
    cin >> a >> b;
    int ret = gcd(a, b);
    cout << "最大公约数是" << ret << endl;
    return 0;
}