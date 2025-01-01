#include <iostream>
using namespace std;

int func(int a, int b)
{
    int maxNum = (a > b) ? a : b;
    int result = maxNum;
    while (true)
    {
        if (result % a == 0 && result % b == 0)
        {
            return result;
        }
        result++;
    }
}

int main()
{
    int a, b;
    cout << "请输入两个整数a b: ";
    cin >> a >> b;
    int ret = func(a, b);
    cout << "最小公倍数是" << ret << endl;
    return 0;
}