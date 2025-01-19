#include <iostream>
using namespace std;
int main()
{
    // 指针所占内存空间
    int a = 10;
    // int *p;
    // p = &a;

    int *p = &a;

    // 在32位操作系统下，指针都是占用4个字节大小，不管是什么数据类型
    // 在64位操作系统下，指针都是占用8个字节大小
    cout << "sizeof (int *) = " << sizeof(int *) << endl;
    cout << "sizeof (int *) = " << sizeof(float *) << endl;
    cout << "sizeof (int *) = " << sizeof(double *) << endl;
    cout << "sizeof (int *) = " << sizeof(char *) << endl;

    return 0;
}