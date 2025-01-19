#include <iostream>
using namespace std;
int main()
{
    // 出现在Switch条件语句中，作用是终止case并跳出switch

    /*

    int val = 0;

    cout << "请选择副本难度：" << endl;
    cout << "1.简单" << endl;
    cout << "2.普通" << endl;
    cout << "3.困难" << endl;

    cin >> val;

    switch (val)
    {
    case 1:
        cout << "您选择的是简单难度。" << endl;
        break;
    case 2:
        cout << "您选择的是普通难度。" << endl;
        break;
    case 3:
        cout << "您选择的是困难难度。" << endl;
        break;
    default:
        break;
    }

    */

    // 出现在循环语句中，作用是跳出当前的循环语句

    /*

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }

        cout << i << endl;
    }

    */

    // 出现在嵌套循环中，跳出最近的内层循环语句

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)
            {
                break;
            }

            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}