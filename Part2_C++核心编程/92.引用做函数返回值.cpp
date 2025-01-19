#include <iostream>
using namespace std;

// 引用做函数的返回值
// 1.不要返回局部变量的引用

// int &test01()
// {
//     int a = 10;
//     return a; // 不要返回局部变量引用
// }

int &test02()
{
    static int a = 10; // 静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
    return a;
}

int main()
{

    // int &ref = test01();
    // cout << "ref " << ref << endl;
    // cout << "ref " << ref << endl; 局部变量存放在栈区中已经被释放

    // 2.函数的调用可以作为左值
    int &ref2 = test02();
    cout << "ref2 " << ref2 << endl;
    cout << "ref2 " << ref2 << endl;
    cout << "ref2 " << ref2 << endl;

    test02() = 1000; // 返回a，即给a赋值1000
    // 如果函数的返回值是引用，这个函数调用可以作为左值
    cout << "ref2 " << ref2 << endl;
    cout << "ref2 " << ref2 << endl;

    return 0;
}