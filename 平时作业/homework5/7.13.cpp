#include <iostream>
using namespace std;

bool isInArr(int numArr[20], int numIn)
{
    int size = 20;
    int isExist = 0;
    for (int i = 0; i < size; i++)
    {
        if (numIn == numArr[i])
        {
            isExist = 1;
        }
    }
    if (isExist == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int numArr[20] = {0};
    int size = 0;
    int num;
    cout << "请输入20个整数(10-100包括10和100),每次输入完按回车:";

    for (int i = 0; i < 20; i++)
    {
        cin >> num;
        if (num < 10 || num > 100)
        {
            cout << "输入的数字不在范围内" << endl;
            i -= 1;
            continue;
        }
        int ret = isInArr(numArr, num);
        if (ret == 0)
        {
            numArr[size] = num;
            size++;
        }
    }

    cout << "数组中不同的数字有: ";
    for (int i = 0; i < size; i++)
    {
        cout << numArr[i] << " ";
    }

    return 0;
}