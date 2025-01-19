#include <iostream>
using namespace std;
int main()
{
    // 一维数组名称用途：

    // 1.可以统计整个数组在内存中的长度
    int arr[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;
    cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;
    cout << "数组中的元素个数为：" << sizeof(arr) / sizeof(arr[0]) << endl;

    // 2.可以获取数组在内存中的首地址
    cout << "数组首地址为：" << arr << endl; // 此代码输出的首地址为16进制
    // cout << "数组首地址为：" << (int)arr << endl; //此时为10进制，但似乎编译器不给运行
    cout << "数组中第一个元素的地址为：" << &arr[0] << endl; // 第一个元素地址其实就是首地址
    cout << "数组中第二个元素的地址为：" << &arr[1] << endl;

    // arr = 100; 错误，数组名是常亮，因此不能进行赋值

    return 0;
}