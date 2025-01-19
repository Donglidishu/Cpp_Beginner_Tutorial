#include <iostream>
using namespace std;

// 把一段经常使用的代码封装起来，减少重复代码
/*
    函数定义的五个步骤：
    1.返回值类型
    2.函数名
    3.参数列表
    4.函数体语句
    5.return表达式
*/

/*  语法

    返回值类型 函数名 (参数列表)
    {
        函数体语句

        return表达式
    }

*/

int add(int num1, int num2) // 定义中的num1 num2为形参
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    int a = 10;
    int b = 20;

    int sum2 = add(a, b); // 此处的a,b为实参，在函数中对应num1和num2
    // 此处定义的sum2即为add()返回的sum值

    cout << sum2 << endl;

    return 0;
}