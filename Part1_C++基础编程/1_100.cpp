#include <iostream>
using namespace std;
int main()
{
    int i = 1;
    int num = 0;
    while (i <= 100)
    {
        num += i;
        i++;
    }
    cout << num << endl;

    return 0;
}