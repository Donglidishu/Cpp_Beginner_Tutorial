#include <iostream>
using namespace std;
int main()
{
    // 声明一个5个元素的数组，并且将元素逆置
    int arr[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}