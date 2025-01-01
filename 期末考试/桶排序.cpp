#include <algorithm> // 用于 std::sort
#include <iostream>
#include <vector>
using namespace std;

// 桶排序函数
void bucketSort(float arr[], int n)
{
    // 创建 n 个桶
    vector<float> buckets[n];

    // 将数组中的元素分配到对应的桶中
    for (int i = 0; i < n; ++i)
    {
        int bucketIndex = n * arr[i]; // 计算桶的索引
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 对每个桶中的元素进行排序
    for (int i = 0; i < n; ++i)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 将排序后的元素合并到原数组
    int index = 0;
    for (int i = 0; i < n; ++i)
    {
        for (float num : buckets[i])
        {
            arr[index++] = num;
        }
    }
}

// 打印数组
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "未排序数组：" << endl;
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "桶排序后数组：" << endl;
    printArray(arr, n);

    return 0;
}