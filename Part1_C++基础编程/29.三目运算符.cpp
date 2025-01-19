#include <iostream>
using namespace std;
int main()
{
    // 创建三个变量abc，比较a和b，将变量大的值赋值给变量c
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b); // 若a大于b，则（？）返回a的值，否则（：）返回b的值
    cout << "c = " << c << endl;

    // 在c++中三目运算符返回的是变量，可以继续赋值
    (a < b ? a : b) = 100; // 继续对返回的变量进行赋值

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}