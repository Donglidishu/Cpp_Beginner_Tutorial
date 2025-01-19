#include <iostream>
using namespace std;

bool isEven(int a)
{
    if (a % 2 == 0)
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
    int arr[5];

    bool result;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << "请输入数字";
        cin >> arr[i];
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        result = isEven(arr[i]);
        cout << "第" << i + 1 << "个数字: ";
        if (result == 1)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}
