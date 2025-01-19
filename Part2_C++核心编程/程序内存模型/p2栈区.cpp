#include <iostream>
using namespace std;

// 栈区数据注意事项 -- 不要返回局部变量的地址
// 栈区的数据由编译器管理开辟和释放

int *fun(int b) // 形参数据也会存放在栈区
{
    b = 100;
    int a = 10;
    return &a; // 尝试返回局部变量地址
}

int main()
{
    int *p = fun(1);

    cout << *p << endl; // 运行到此处程序自动释放*p的内存
    cout << *p << endl; // 此处显示的值已经是未定义的空指针

    return 0;
}