#include <iostream>
using namespace std;

// 改进版选择排序
void selectionSortImproved(int arr[], int n)
{
    int left = 0, right = n - 1; // 未排序部分的起始和末尾
    while (left < right)
    {
        int minIndex = left, maxIndex = right;
        // 遍历未排序部分，找到最小值和最大值
        for (int i = left; i <= right; ++i)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i; // 更新最小值索引
            }
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i; // 更新最大值索引
            }
        }

        // 将最小值放到 left 位置
        swap(arr[left], arr[minIndex]);

        // 如果最大值被换到了 minIndex 的位置，更新 maxIndex
        if (maxIndex == left)
        {
            maxIndex = minIndex;
        }

        // 将最大值放到 right 位置
        swap(arr[right], arr[maxIndex]);

        // 缩小未排序部分的范围
        left++;
        right--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "未排序数组：" << endl;
    printArray(arr, n);

    selectionSortImproved(arr, n);

    cout << "改进选择排序后数组：" << endl;
    printArray(arr, n);

    return 0;
}