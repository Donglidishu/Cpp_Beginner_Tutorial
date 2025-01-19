#include <iostream>
using namespace std;
int main()
{
    int num = 0;

    do
    {
        num++;

        int a = num / 10;
        int b = num % 10;

        if (a == 7 || b == 7 || num % 7 == 0)
        {
            cout << "敲桌子" << endl;
        }

        else
        {
            cout << num << endl;
        }

    } while (num < 100);

    return 0;
}