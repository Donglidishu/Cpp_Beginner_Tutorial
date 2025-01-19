#include <iomanip> // 用于设置输出格式
#include <iostream>
using namespace std;

int main()
{
    const double initialAmount = 24.0; // 初始本金
    const int years = 387;             // 年数
    double rate[] = {0.05, 0.10};      // 利率范围

    // 遍历不同的利率
    for (double r : rate)
    {
        double amount = initialAmount; // 重置本金
        // 计算复利
        for (int i = 0; i < years; i++)
        {
            amount += amount * r;
        }
        // 输出结果
        cout << fixed << setprecision(2);
        cout << "利率 " << r * 100 << "% 时的最终金额为: $" << amount << endl;
    }

    return 0;
}