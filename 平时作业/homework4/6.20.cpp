#include <iostream>
using namespace std;

// 函数：判断第二个整数是否是第一个整数的倍数
bool multiple(int a, int b)
{
    if (b == 0)
    {
        return false;
    }
    return a % b == 0;
}

int main()
{
    int num1, num2;

    cout << "输入一系列整数对（以两个数字一组，输入 0 0 结束）：" << endl;

    while (true)
    {
        cout << "输入两个整数：";
        cin >> num1 >> num2;

        // 如果输入是 0 0，则结束
        if (num1 == 0 && num2 == 0)
        {
            break;
        }

        // 判断倍数关系
        if (multiple(num1, num2))
        {
            cout << num2 << " 是 " << num1 << " 的倍数。" << endl;
        }
        else
        {
            cout << num2 << " 不是 " << num1 << " 的倍数。" << endl;
        }
    }

    cout << "程序结束。" << endl;

    return 0;
}