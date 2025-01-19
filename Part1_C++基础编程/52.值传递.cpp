#include <iostream>
using namespace std;

// 值传递
// 定义函数，实现两个数字交换

// 如果函数不需要返回值，声明的时候可以写void (无类型)
void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
    cout << num1 << endl;
    cout << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << num1 << endl;
    cout << num2 << endl;

    // return; 不需要返回值的时候也可以不写return
}

int main()
{
    int a = 10;
    int b = 20;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 函数中形参发生改变不影响实参
    // 此处表现为函数中num1和num2进行值交换，但实参a和b并未发生交换

    return 0;
}