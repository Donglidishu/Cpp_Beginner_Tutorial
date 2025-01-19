#include <iostream>
using namespace std;

// 不在任何函数体或类体中的变量即为全局变量
int g_a = 10;
int g_b = 10;

int main()
{
    // 局部变量和局部常量在一块
    // 全局变量、全局常量、静态变量在一块
    cout << "全局变量a的地址:" << &g_a << endl;
    cout << "全局变量b的地址:" << &g_b << endl;

    // 局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量a的地址:" << &a << endl;
    cout << "局部变量b的地址:" << &b << endl;

    // 静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址:" << &s_a << endl;
    cout << "静态变量s_b的地址:" << &s_b << endl;

    // 常量
    // 字符串常量
    cout << "全局常量c_g_a的地址为:" << &"helloworld" << endl;
    cout << "全局常量c_g_b的地址为:" << &"helloworld" << endl;

    // const修饰的变量：const修饰的全局变量和局部变量
    const int c_l_a = 10; // c~const g~global l~local
    const int c_l_b = 10;

    cout << "局部常量c_l_a的地址为:" << &c_l_a << endl;
    cout << "局部常量c_l_b的地址为:" << &c_l_b << endl;

    // 不在全局区中：局部变量、const修饰的局部变量（局部常量）
    // 全局区：全局变量、静态变量、static关键字、常量（字符串常量，const修饰的全局变量【全局常量】）
    return 0;
}