#include <iostream>
using namespace std;
// 引用的本质在c++内部实现是一个指针常量
// 发现是引用，转换成int* const ref = &a;
void func(int &ref)
{
    ref = 100; // ref是引用，自动转化成*ref = 100;
}

int main()
{
    int a = 10;

    // 自动转换为int *const ref = &a;指针常量是指向不可改，也就说明了为什么引用不可改
    int &ref = a;
    ref = 20; // 内部发现ref是引用,自动帮我们转换为*ref = 20;

    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    func(a);

    return 0;
}