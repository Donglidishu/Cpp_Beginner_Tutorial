#include <iostream>
using namespace std;
int main()
{
    int count,n;
    for (int i = 1; i < 6; i++)
    {
        count = 1;
        n = 1;
        while (count <= i)
        {
            n *= count;
            count++;
        }
        cout << i << "! \t" << n << endl; 
    }
    

    return 0;
}