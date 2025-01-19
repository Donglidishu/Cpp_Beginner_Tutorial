#include <iostream>
using namespace std;

// 创建冒泡函数
void BobbleSort(int *array, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// 打印数组
void arrprint(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << endl;
    }
}

int main()
{
    // 创建数组
    int arr[10] = {4, 6, 5, 2, 7, 8, 1, 9, 10, 3};

    int len = sizeof(arr) / sizeof(arr[0]);

    BobbleSort(arr, len);

    arrprint(arr, len);

    return 0;
}