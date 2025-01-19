#include <iostream>
using namespace std;

// 判断一个数是否是完数
bool isperfect(int number)
{
    int sum = 0; // 用于存储因子和

    // 遍历所有可能的因子（不包括自身）
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i; // 将因子加到和中
        }
    }

    // 判断因子和是否等于原数
    return sum == number;
}

int main()
{
    cout << "1 到 1000 之间的完数有：" << endl;

    // 查找并打印 1 到 1000 之间的所有完数
    for (int i = 1; i <= 1000; i++)
    {
        if (isperfect(i))
        {
            cout << i << " 是一个完数" << endl;
        }
    }

    // 测试大于 1000 的数
    cout << "\n测试大于 1000 的完数：" << endl;
    int testNumber = 8128; // 一个大于 1000 的已知完数
    if (isperfect(testNumber))
    {
        cout << testNumber << " 是一个完数" << endl;
    }
    else
    {
        cout << testNumber << " 不是一个完数" << endl;
    }

    return 0;
}