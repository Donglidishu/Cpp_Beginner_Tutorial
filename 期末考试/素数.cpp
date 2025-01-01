#include <iostream>
using namespace std;

// 判断一个数是否是素数
bool isPrime(int n)
{
    if (n < 2)
        return false; // 小于 2 的数不是素数
    for (int i = 2; i * i <= n; ++i)
    { // 遍历到 i * i <= n
        if (n % i == 0)
        {
            return false; // 如果能被整除，就不是素数
        }
    }
    return true; // 没有因子，则是素数
}

int main()
{
    int N;
    cout << "请输入要列举素数的最大范围 N：";
    cin >> N;

    cout << "1 ~ " << N << " 之间的素数如下：" << endl;
    for (int i = 1; i <= N; ++i)
    {
        if (isPrime(i))
        {
            cout << i << " "; // 打印素数
        }
    }
    cout << endl;

    return 0;
}