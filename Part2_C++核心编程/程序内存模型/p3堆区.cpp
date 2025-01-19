#include <iostream>
using namespace std;

int *func()
{
    // 利用new关键字 可以将数据开辟到堆区
    // 指针本质上是局部变量，放在栈上，指针保存的数据存储在堆区
    int *p = new int(10); // 返回的是地址，所以使用指针接收
    return p;
}

int main()
{
    // 在堆区开辟数据
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    // 堆区数据特点：由程序员管理开辟和释放、利用new关键字开辟内存
    return 0;
}