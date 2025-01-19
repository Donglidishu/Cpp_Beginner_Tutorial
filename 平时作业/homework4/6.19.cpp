#include <cmath>
#include <iostream>
using namespace std;

double hypotenuse(double a, double b)
{
    double hyp;
    hyp = pow(a * a + b * b, 0.5);
    return hyp;
}

int main()
{
    double a = 0, b = 0, hyp;
    for (int i = 0; i < 3; i++)
    {
        cout << "请输入第一个直角边: ";
        cin >> a;
        cout << "请输入第二个直角边: ";
        cin >> b;
        hyp = hypotenuse(a, b);
        cout << "斜边为: " << hyp << endl;
    }

    return 0;
}