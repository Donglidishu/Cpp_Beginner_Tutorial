#include <iostream>
using namespace std;

bool huiwen(int a)
{
    int wan = a / 10000;
    int qian = (a / 1000) % 10;
    int bai = (a / 100) % 10;
    int shi = (a / 10) % 10;
    int ge = a % 10;

    int b = ge * 10000 + shi * 1000 + bai * 100 + qian * 10 + wan;
    if (b == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (true)
    {
        int a = 0;
        cout << "请输入一个五位数,或输入-1退出：" << endl;
        cin >> a;

        if (a == -1)
        {
            break;
        }
        

        bool flag = huiwen(a);
        if (flag == 1)
        {
            cout << "输入的数是回文数" << endl;
        }
        else
        {
            cout << "输入的数不是回文数" << endl;
        }
    }

    return 0;
}