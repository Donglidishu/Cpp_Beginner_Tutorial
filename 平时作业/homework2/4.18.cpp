#include <iostream>
using namespace std;
int main()
{
    int N = 1;
    cout << "N\t";
    cout << "10*N\t";
    cout << "100*N\t";
    cout << "1000*N" << endl;

    while (N < 6)
    {
        cout << N << "\t";

        cout << N * 10 << "\t";

        cout << N * 100 << "\t";

        cout << N * 1000 << endl;
        N++;
    }

    return 0;
}