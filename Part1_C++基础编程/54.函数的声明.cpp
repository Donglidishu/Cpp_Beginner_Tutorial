#include <iostream>
using namespace std;

// 声明：提前告诉编译器函数的存在，可以存在多次
// 定义只可以存在一次
// 声明
int max(int a, int b);
int max(int a, int b);

int main()
{
    int a = 10;
    int b = 20;
    cout << max(a, b) << endl;

    return 0;
}

// 定义
int max(int a, int b)
{
    return a < b ? a : b;
}