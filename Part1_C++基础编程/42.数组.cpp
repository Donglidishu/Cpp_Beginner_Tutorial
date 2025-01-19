#include <iostream>
using namespace std;
int main()
{
    // 数组特点：1.数组中的每个数据元素都是相同的数据类型
    //         2.数组是由连续的内存位置组成的

    // 数组的三种形式：

    // 1.数据类型 数组名[ 数组长度 ];
    int arr[5];
    // 对数组中的元素进行赋值
    // 数组中的元素是从0开始索引的
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << "arr" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    // 2.数据类型 数组名[ 数组长度 ] = { val1, val2.....};
    int arr2[5] = {10, 20, 30, 40, 50};
    cout << "arr2" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << arr2[j] << endl;
    }

    // 3.数据类型 数组名[ ] = { val1, val2.....};
    int arr3[] = {10, 20, 30, 40, 50};
    cout << "arr3" << endl;
    for (int k = 0; k < 5; k++)
    {
        cout << arr3[k] << endl;
    }

    return 0;
}