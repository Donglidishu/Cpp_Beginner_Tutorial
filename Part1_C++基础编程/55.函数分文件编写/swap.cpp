#include "swap.h"

// 源文件中给出函数定义
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << a << endl;
    cout << b << endl;
}
