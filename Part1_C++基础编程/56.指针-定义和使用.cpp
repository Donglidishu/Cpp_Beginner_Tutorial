#include <iostream>
using namespace std;
int main()
{
    // 1.定义指针
    int a = 10;

    // 指针定义的语法：数据类型 * 指针变量名
    int *p;

    // 让指针记录变量a的地址
    p = &a;

    cout << "变量a的地址为:" << &a << endl;
    cout << "指针p为:" << p << endl;

    // 2.使用指针
    // 可以通过解引用的方法找到指针指向的内存
    // 指针前加 * 代表解引用，找到指针指向的内存中的数据
    *p = 1000; // 即找到了指针p所指向的那个数据，通过指针间接访问和修改a的内存中的数据

    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;

    return 0;
}