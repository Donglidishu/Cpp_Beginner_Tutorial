#include <iostream>
using namespace std;

void printArray(const int arr[], int start, int end)
{
    if (start == end)
    {
        cout << arr[end] << endl;
        return;
    }
    cout << arr[start] << endl;
    return printArray(arr, start + 1, end);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, 0, size - 1);
    return 0;
}