#include <iostream>
using namespace std;
int main()
{
    // 二位数组的定义方式

    // 1.数据类型 数组名［行数][列数];
    int arr[2][3];
    arr[0][0] = 1;
    // 依次赋值即可

    // 2.数据类型 数组名［行数 ][列数］={{数据1,数据2},{数据3,数据4}};
    // ！推荐第二种 可读性更强！
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "arr2:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    // 3.数据类型 数组名［行数][列数］={数据1,数据2,数据3,数据4};
    int arr3[2][3] = {1, 2, 3, 4, 5, 6}; // 定义为两行三列的二维数组，可自动划分三个元素为一行
    cout << "arr3:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    // 4.数据类型 数组名[ ][ 列数］={数据1,数据2,数据3,数据4};
    int arr4[][3] = {1, 2, 3, 4, 5, 6}; // 已经声明有三列，可以不写行数，让程序自己区分
    cout << "arr4:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr4[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}