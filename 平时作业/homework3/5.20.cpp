#include <iostream>
using namespace std;

int main()
{
    const int limit = 500; // 边长最大值
    int count = 0;         // 计数三元组个数

    // 三层循环暴力枚举所有可能的边长
    for (int a = 1; a <= limit; ++a)
    {
        for (int b = a; b <= limit; ++b)
        { // b >= a 保证不重复
            for (int c = b; c <= limit; ++c)
            { // c >= b 保证不重复
                if (a * a + b * b == c * c)
                { // 判断是否满足毕达哥拉斯定理
                    cout << "三元组: (" << a << ", " << b << ", " << c << ")" << endl;
                    ++count;
                }
            }
        }
    }

    cout << "总共有 " << count << " 个毕达哥拉斯三元组。" << endl;
    return 0;
}