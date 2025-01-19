#include <iostream>
using namespace std;
int main()
{
    // 空指针：指针变量指向内存中编号为0的空间
    // 用途：初始化指针变量
    int *p = NULL;

    // 注意：空指针指向的内存是不可以访问的
    // 0 ~ 255之间的内存编号是系统占用的，因此不可以访问
    *p = 100; // 运行会报错: EXC_BAD_ACCESS (code=1, address=0x0)

    // 野指针
    int *q = (int *)0x1100; // 指针变量直接指向非法内存空间
    // 访问野指针报错
    cout << *q << endl;

    // 空指针和野指针都不是我们申请的空间，因此不要访问
    return 0;
}