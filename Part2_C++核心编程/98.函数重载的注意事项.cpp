#include <iostream>
using namespace std;

// 注意事项
// 1.引用作为函数重载的条件
void func(int &a) // int &a = 10;不合法
{
    cout << "调用func(int &a)" << endl;
}

void func(const int &a) // const int &a = 10; 合法，编译器会创建一个临时变量存储 10，并让 a 引用该临时变量。
{
    cout << "调用func(const int &a)" << endl;
}

// 2.函数重载遇到默认参数
//函数重载时尽量避免使用默认参数
void func2(int a, int b = 10)
{
    cout << "调用func2(int a,int b = 10)" << endl;
}

void func2(int a)
{
    cout << "调用func2(int a)" << endl;
}

int main()
{
    int a = 10;
    func(a);
    func(10);

    // func2(10);存在歧义（二义性），两个func2理论上都可以走，尽量避免
    return 0;
}