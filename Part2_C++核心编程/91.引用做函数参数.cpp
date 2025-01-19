#include <iostream>
using namespace std;

// 作用：函数传参时，可以利用引用的技术让形参修饰实参
// 优点：可以简化指针修饰实参

// 1.值传递
void swap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp; // 不改变main中实参的值
}

// 2.地址传递
void swap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3.引用传递
void swap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp; // 引用传递形参会修饰实参
}

int main()
{
    int a = 10;
    int b = 20;

    // swap01(a,b);  a = 10, b = 20;
    // swap02(&a, &b);  a = 20, b = 10;

    swap03(a, b);
    cout << "swap03 a = " << a << endl;
    cout << "swap03 b = " << b << endl;

    return 0;
}