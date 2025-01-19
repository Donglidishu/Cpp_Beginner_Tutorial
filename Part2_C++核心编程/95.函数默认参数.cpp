#include <iostream>
using namespace std;

// 如果自行传入参数，则使用传入值，否则使用默认值
// 语法：返回值类型 函数名（ 形参 = 默认值 ）{}
int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

// 注意事项
// 1.如果某个位置参数有默认值，则从这个参数起从左到右的所有参数都需要有默认值

// 2.函数声明和函数实现只能有一个有默认参数
// int func2(int a, int b) 声明

// int func2(int a = 10, int b = 20) 实现
// {
//     return a + b;
// }

int main()
{
    cout << func(10, 30) << endl;
    return 0;
}