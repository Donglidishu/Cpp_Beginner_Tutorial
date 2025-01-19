#include <iostream>
using namespace std;

double factorial(int n) // 阶乘函数
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
    int n, x;
    cout << "请输入想要的e^x的精度(累加的项数): ";
    cin >> n;
    cout << "请输入x: ";
    cin >> x;

    double e_x = 1.0;
    int i = 1;

    int x_count = 1.0;
    while (i <= n)
    {
        x_count *= x;
        e_x += x_count / factorial(i);
        i++;
    }
    cout << "e^" << x << " = " << e_x << endl;

    return 0;
}
