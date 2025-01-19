#include <iostream>
using namespace std;

// 实现通用 对数组进行排序的函数
// 规则 从大到小
// 算法 选择
// 测试 char数组 & int数组

// 交换函数模板
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序模板
template <typename T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            mySwap(arr[max], arr[i]);
        }
    }
}

// 打印数组模板
template <typename T>
void printArr(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

// 测试char
void test01()
{
    char arr[] = "acpyfbs";
    int len = sizeof(arr) / sizeof(char);
    mySort(arr, len);
    printArr(arr, len);
}

// 测试int
void test02()
{
    int intArr[] = {7, 5, 8, 1, 3, 9, 2, 4, 6};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArr(intArr, num);
}
int main()
{
    test02();
    return 0;
}