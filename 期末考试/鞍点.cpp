#include <iostream>
using namespace std;

// 鞍点：在该行中为最大值，且为所在列的最小值

void saddlePoint(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        int tempj = matrix[i][0]; // 初始化为当前行第一个元素
        int index = 0;            // 初始化最小值索引为 0

        // 找到当前行中最小值及其列索引
        for (int j = 1; j < 4; j++)
        {
            if (matrix[i][j] < tempj)
            {
                tempj = matrix[i][j];
                index = j;
            }
        }

        // 检查该列是否为最大值
        bool isSaddlePoint = true;
        for (int k = 0; k < 4; k++)
        {
            if (matrix[k][index] > matrix[i][index])
            {
                isSaddlePoint = false;
                break; // 提前退出
            }
        }

        if (isSaddlePoint)
        {
            cout << "存在鞍点，索引为 (" << i << " , " << index << ") = " << matrix[i][index] << endl;
        }
    }
}

int main()
{
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {8, 6, 5, 7},
        {9, 7, 11, 10},
        {13, 14, 12, 16}};

    saddlePoint(matrix);
    return 0;
}