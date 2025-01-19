#include <iostream>
using namespace std;

void tax(double rate, double month_income)
{
    double tax;
    tax = (month_income - 5000) * rate;
    cout << "您本月缴纳个人所得税  " << tax << endl;
    cout << "税后收入是 " << month_income - tax << "元" << endl;
    cout << "感谢依法纳税，谢谢使用！" << endl;
}

void case1()
{
    double month_income, rate;
    cout << "请输入您本月的收入总额（元）：" << endl;
    cout << "本月收入总额";
    cin >> month_income;

    if (month_income <= 5000)
    {
        cout << "无需缴税" << endl;
    }
    else if (month_income <= 8000)
    {
        rate = 0.03;
        tax(rate, month_income);
    }
    else if (month_income <= 17000)
    {
        rate = 0.1;
        tax(rate, month_income);
    }
    else if (month_income <= 30000)
    {
        rate = 0.2;
        tax(rate, month_income);
    }
    else if (month_income <= 40000)
    {
        rate = 0.25;
        tax(rate, month_income);
    }
    else if (month_income <= 60000)
    {
        rate = 0.3;
        tax(rate, month_income);
    }
    else if (month_income <= 85000)
    {
        rate = 0.35;
        tax(rate, month_income);
    }
    else
    {
        rate = 0.45;
        tax(rate, month_income);
    }
}

struct Tax
{
    double total_tax;
    double pre_tax;
};

void case2()
{
    Tax arr[12];
    int work_month = 0;
    double month_income;

    cout << "请输入本月收入总额（元）：" << endl;
    cout << "本月收入总额：";
    cin >> month_income;

    cout << "请输入当月月份：";
    cin >> work_month;

    cout << "计算截止当月累计预扣税额！" << endl;
    cout << "......" << endl;

    int month_count = 0;
    double total_money; // 到当前月份年度累计应交税所得额
    for (int i = 1; i < work_month + 1; i++)
    {
        double rate = 0;
        total_money = (month_income - 5000) * i;
        if (total_money <= 36000)
        {
            rate = 0.03;
        }
        else if (total_money <= 144000)
        {
            rate = 0.1;
        }
        else if (total_money <= 300000)
        {
            rate = 0.2;
        }
        else if (total_money <= 420000)
        {
            rate = 0.25;
        }
        else if (total_money <= 660000)
        {
            rate = 0.3;
        }
        else if (total_money <= 960000)
        {
            rate = 0.35;
        }
        else
        {
            rate = 0.45;
        }

        arr[i - 1].total_tax = total_money;
        arr[i - 1].pre_tax = (month_income - 5000) * rate;

        cout << "-----------------------------------------------------------" << endl;
        cout << i << "月累积预扣预缴应纳税所得额为: " << arr[i - 1].total_tax << "   预扣税: " << arr[i - 1].pre_tax << endl;
        month_count++;
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << month_count << "月份预扣预缴应纳税所得额为: " << arr[month_count - 1].total_tax << endl;
    cout << "您" << month_count << "月份缴纳个人所得税" << arr[month_count - 1].pre_tax << "元" << endl;
    cout << "税后收入是 " << month_income - arr[month_count - 1].pre_tax << "元" << endl;
    cout << endl;
    cout << "感谢依法纳税，谢谢使用！" << endl;
}

int main()
{
    int choice = 0;
    cout << "----------------------------" << endl;
    cout << "1 预扣纳税方案" << endl;
    cout << "2 累计预扣方案" << endl;
    cout << "----------------------------" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1: {
        case1();
        break;
    }
    case 2: {
        case2();
        break;
    }
    }

    return 0;
}