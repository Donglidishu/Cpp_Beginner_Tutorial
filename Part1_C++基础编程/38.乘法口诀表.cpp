#include <iostream>
using namespace std;
int main()
{
    for (int h = 1; h <= 9; h++)
    {
        for (int l = 1; l <= h; l++) // 列数小于等于行数
        {
            cout << l << " * " << h << " = " << l * h << "\t";
        }
        cout << endl;
    }

    return 0;
}