#include <iostream>

using namespace std;

void printPrimes(int array[], int size)
{
    cout << "2~999的质数有: ";
    for (int i = 2; i < size; i++)
    {
        if (array[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    const int SIZE = 1000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;

    for (int i = 2; i * i < SIZE; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = i * i; j < SIZE; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    printPrimes(arr, SIZE);

    return 0;
}