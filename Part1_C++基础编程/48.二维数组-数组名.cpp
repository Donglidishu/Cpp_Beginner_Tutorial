#include <iostream>
using namespace std;
int main()
{
    // 1.可以查看占用内存空间大小
    int arr[2][3] =
    {
            {1, 2, 3},
            {4, 5, 6}
    };
    cout << "二维数组占用内存空间为：" << sizeof(arr) << endl;
    cout << "二维数组第一行占用内存空间为：" << sizeof(arr[1]) << endl; // 二维数组按行存储，无法用同样的方法查看列占用的内存空间大小(可以用元素占用内存 * 行数)
    cout << "二维数组第一个元素占用内存为：" << sizeof(arr[0][0]) << endl;

    cout << "二维数组的行数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "二维数组的列数为：" << sizeof(arr[2]) / sizeof(arr[0][0]) << endl;

    // 2.查看二维数组首地址
    cout << "二维数组的首地址为：" << arr << endl;
    cout << "第一行首地址：" << arr[0] << endl;
    cout << "第一行第一个元素首地址：" << &arr[0][0] << endl; // 以上三者相同

    cout << "第一行第二个元素首地址：" << &arr[0][1] << endl;

    cout << "第二行首地址：" << arr[1] << endl;

    return 0;
}