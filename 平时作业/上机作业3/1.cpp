#include <iostream>
using namespace std;

void tax(float rate, float tax)
{
    tax *= rate;
    cout << "税额为 " << tax << endl;
}

int main()
{
    float month_income, zx, zx_fj, others, pre_tax, rate;
    cout << "请输入月工资：";
    cin >> month_income;
    cout << "请输入专项扣除：";
    cin >> zx;
    cout << "请输入专项扣除(附加)：";
    cin >> zx_fj;
    cout << "请输入依法确定的其他扣除：";
    cin >> others;

    pre_tax = month_income - 5000 - zx - zx_fj - others;

    if (month_income <= 5000)
    {
        cout << "无需缴税" << endl;
    }
    else if (month_income <= 8000)
    {
        rate = 0.03;
        tax(rate, pre_tax);
    }
    else if (month_income <= 17000)
    {
        rate = 0.1;
        tax(rate, pre_tax);
    }
    else if (month_income <= 30000)
    {
        rate = 0.2;
        tax(rate, pre_tax);
    }
    else if (month_income <= 40000)
    {
        rate = 0.25;
        tax(rate, pre_tax);
    }
    else if (month_income <= 60000)
    {
        rate = 0.3;
        tax(rate, pre_tax);
    }
    else if (month_income <= 85000)
    {
        rate = 0.35;
        tax(rate, pre_tax);
    }
    else
    {
        rate = 0.45;
        tax(rate, pre_tax);
    }

    return 0;
}