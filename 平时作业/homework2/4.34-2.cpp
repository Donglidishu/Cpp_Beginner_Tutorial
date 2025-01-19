#include <iostream>
using namespace std;

double factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    double count = 1;
    while (n > 0)
    {
        count *= n;
        n--;
    }
    return count;
}

int main()
{
    int n = 0;
    cout << "请输入想要的e的精度(累加的项数): ";
    cin >> n;
    double e = 1.0;
    int i = 1;
    while (i <= n )
    {
        e += 1.0/factorial(i);
        i++;
    }
    cout << "e = " << e << endl;
    
    
    return 0;
}
