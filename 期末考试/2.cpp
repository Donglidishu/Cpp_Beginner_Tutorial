#include <iostream>
using namespace std;

int main()
{
    const int rows = 5;
    int triangle[rows][rows] = {0};

    for (int i = 0; i < rows; i++)
    {
        triangle[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows - i - 1; k++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}