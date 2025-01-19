#include <iostream>
using namespace std;

// 普通函数与函数模板调用规则
//  1.如果函数模板和普通函数都可以调用，优先调用普通函数
//  2.可以通过空模板参数列表强制调用函数模板
//  3.函数模板可以发生函数重载
//  3.如果函数模板可以产生更好的匹配，优先调用函数模板

// 提示：写了函数模板最好就不要再写同名普通函数了

void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

template <typename T>
void myPrint(T a, T b)
{
    cout << "调用的模板" << endl;
}

template <typename T>
void myPrint(T a, T b, T c)
{
    cout << "调用重载的模板" << endl;
}

void test01()
{
    // 1、如果函数模板和普通函数都可以实现，优先调用普通函数
    //  注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
    int a = 10;
    int b = 20;
    myPrint(a, b); // 调用普通函数

    // 通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);

    // 函数模板的重载
    myPrint<>(a, b, 100);

    // 如果函数模板可以产生更好的匹配，优先调用函数模板
    char a1 = 'a';
    char a2 = 'b';
    myPrint(a1, a2); // 因为走函数模板不需要进行隐式类型转换，因此模版更好匹配
}

int main()
{
    test01();
    return 0;
}