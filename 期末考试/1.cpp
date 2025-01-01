#include <iostream>
using namespace std;

int main()
{
    int matrix[3][3] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}};

    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < 3; i++)
    {
        count1 += matrix[i][i];
    }
    for (int i = 0; i < 3; i++)
    {
        count2 += matrix[i][2 - i];
    }
    cout << "主对角线: " << count1 << endl;
    cout << "次对角线: " << count2 << endl;

    return 0;
}