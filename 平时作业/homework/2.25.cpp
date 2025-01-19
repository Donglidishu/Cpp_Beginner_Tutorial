#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 0;

    cout << "请输入第一个整数：" << endl;
    cin >> a;
    cout << "请输入第二个整数：" << endl;
    cin >> b;

    if (a % b == 0)
    {
        cout << a << "是" << b << "的倍数" << endl;
    }
    else
    {
        cout << a << "不是" << b << "的倍数" << endl;
    }

    return 0;
}