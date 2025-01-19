#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "第一个元素为：" << arr[0] << endl;

    int *p = arr; // arr就是数组首地址

    cout << "利用指针访问第一个元素：" << *p << endl;

    int *p2 = arr;
    cout << "利用指针输出数组中的元素：" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << *p2 << endl;
        p2++;
    }

    return 0;
}