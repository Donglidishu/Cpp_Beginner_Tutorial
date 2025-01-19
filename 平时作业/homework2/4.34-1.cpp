#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "请输入n: ";
    cin >> n;

    int count = 1;
    while (n > 0)
    {
        count *= n;
        n--;
    }

    cout << "n! = " << count << endl;
    return 0;
}
