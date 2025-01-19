#include <iostream>
using namespace std;
int main()
{
    // 使用冒泡排序实现升序序列
    int arr[10] = {4, 2, 8, 0, 6, 5, 7, 1, 3, 9};
    int len = (sizeof(arr)/sizeof(arr[0]));

    // 开始冒泡排序
    // 总排序轮数 == 元素个数 - 1
    for (int i = 0; i < len - 1; i++)
    {
        // 内层排序轮数 == 元素个数 - 当前轮数 - 1
        for (int j = 0; j < len - i - 1; j++)
        {
            // 如果第一个数字比第二个数字大则交换这两个数字
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < len; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}