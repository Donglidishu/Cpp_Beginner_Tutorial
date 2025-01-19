#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

pair<double, double> equalPrincipalPayment(double loanAmount, double repaymentYears, double monthlyRate)
{
    double monthlyPayment = 0, monthlyInterest = 0, monthlyPrincipal = 0, totalInterest = 0, repayCount = 0;
    double previousMonthInterest = 0, interestDifference = 0;
    int m = repaymentYears * 12;
    int repaymentMonth = 1;

    while (repaymentMonth <= m)
    {
        monthlyPrincipal = loanAmount / m;                         // 每月应还本金
        monthlyInterest = (loanAmount - repayCount) * monthlyRate; // 每月应还利息
        monthlyPayment = monthlyPrincipal + monthlyInterest;       // 每月总还款额
        repayCount += monthlyPrincipal;                            // 更新已还本金累计额
        totalInterest += monthlyInterest;                          // 累加总利息

        cout << "第 " << repaymentMonth << " 月还款: " << monthlyPayment
             << " 本金: " << monthlyPrincipal
             << " 利息: " << monthlyInterest << endl;
        if (repaymentMonth > 1)
        {
            interestDifference = previousMonthInterest - monthlyInterest;
        }

        // 更新前一个月的利息
        previousMonthInterest = monthlyInterest;

        repaymentMonth++;
    }

    return make_pair(totalInterest, interestDifference); // 返回总利息
}

double equalTotalPayment(double loanAmount, double repaymentYears, double monthlyRate)
{
    double monthlyPayment = 0, monthlyInterest = 0, monthlyPrincipal = 0, totalInterest = 0;
    int m = repaymentYears * 12;
    int repaymentMonth = 1;

    while (repaymentMonth <= m)
    {
        monthlyPayment = loanAmount * (monthlyRate * pow(1 + monthlyRate, m)) / (pow(1 + monthlyRate, m) - 1);
        monthlyInterest = loanAmount * monthlyRate * (pow(1 + monthlyRate, m) - pow(1 + monthlyRate, repaymentMonth)) / (pow(1 + monthlyRate, m) - 1);
        monthlyPrincipal = loanAmount * monthlyRate * pow(1 + monthlyRate, repaymentMonth - 1) / (pow(1 + monthlyRate, m) - 1);
        cout << "第 " << repaymentMonth << " 月还款" << monthlyPayment << " 本金" << monthlyPrincipal << " 利息" << monthlyInterest << endl;
        repaymentMonth++;
    }

    totalInterest = m * monthlyPayment - loanAmount;

    return totalInterest;
}

int main()
{
    double loanAmount, repaymentYears, annualRate, monthlyRate;
    cout << "----------房贷月供计算器----------" << endl;
    cout << "输入贷款总额（元）";
    cin >> loanAmount;
    cout << endl;
    cout << "输入还款年限：";
    cin >> repaymentYears;
    cout << endl;
    cout << "输入当前年利率：";
    cin >> annualRate;
    cout << endl;
    monthlyRate = annualRate / 1200;

    cout << "----------------------------------" << endl;
    cout << "提供两种还款方式: 1.等额本金 2.等额本息" << endl;
    cout << "----------------------------------" << endl;

    cout << "贷款总额" << loanAmount << endl;
    cout << "贷款年限" << repaymentYears << "年" << endl;
    cout << "月利率" << monthlyRate << endl;

    auto TotalequalPrincipalPayment = equalPrincipalPayment(loanAmount, repaymentYears, monthlyRate);

    cout << "采用等额本息，还款记录如下：" << endl;
    double TotalequalTotalPayment = equalTotalPayment(loanAmount, repaymentYears, monthlyRate);

    cout << "等额本金总利息是: " << TotalequalPrincipalPayment.first << " 月降利息是: " << TotalequalPrincipalPayment.second << endl;
    cout << "等额本息总利息是: " << TotalequalTotalPayment << endl;

    return 0;
}