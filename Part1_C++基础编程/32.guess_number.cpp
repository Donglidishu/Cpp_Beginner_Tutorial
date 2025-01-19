#include <iostream>
using namespace std;
#include <ctime> //包含time系统时间头文件

int main()
{

    // 需求：生成一个1~100的随机数，用户猜数字，提示猜大了或者猜小了，直到猜中

    // 以系统时间作为随机数种子，防止每次随机数都一样
    srand((unsigned int)time(NULL));

    int num = rand() % 100 + 1; // rand() % 100指的是生成0~99的随机数，这里需要随机数为1~100，故+1

    // 用户输入数据
    int val = 0;
    cout << "guess a number:" << endl;

    while (1)
    {
        cin >> val;

        if (val > num)
        {
            cout << "too big" << endl;
        }
        else if (val < num)
        {
            cout << "too small" << endl;
        }
        else
        {
            cout << "good" << endl;
            // 猜对后退出
            break;
        }
    }

    return 0;
}