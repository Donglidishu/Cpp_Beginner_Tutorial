#include <iostream>
using namespace std;

// 函数重载，可以让函数名相同，提高复用性
// 条件:
// 1.在同一作用域下
//  2.函数名称相同
//  3.函数参数类型不同，或者参数个数不同，或者参数顺序不同

// 注意事项:
// 函数的返回值不可以作为重载的条件
//  例如 void func(){} 和 int func(){}不可以同时存在，调用函数的时候会有歧义

void func()
{
    cout << "1" << endl;
}

void func(int a)
{
    cout << "2" << endl;
}

void func(double a)
{
    cout << "3" << endl;
}

void func(double a, int b)
{
    cout << "4" << endl;
}

void func(int a, double b)
{
    cout << "5" << endl;
}

int main()
{

    return 0;
}