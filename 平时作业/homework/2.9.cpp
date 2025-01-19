#include <iostream>
using namespace std;
int main()
{
    int b = 0;
    int c = 0;
    cout << "Enter two numbers:" << endl;
    cin >> b;
    cin >> c;
    int a = b * c; // 进行工资的计算
    cout << "工资为：" << a << endl;

    return 0;
}