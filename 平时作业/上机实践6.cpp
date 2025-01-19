#include <algorithm>
#include <iostream>
#include <string>

#define MAX 10
using namespace std;

struct techinf
{
    string num;
    string name;
    string title;
    int workage;
    double dSalary[15];
    double dTax;
    double lastsalary;
};

struct techBook
{
    techinf personArray[MAX];
    int m_Size;
};

double taxCount(double month_income);

void setInfo(techinf *t)
{

    cout << "请输入职工工号: ";
    cin >> t->num;
    cout << "请输入姓名: ";
    cin >> t->name;
    cout << "请输入职称: ";
    cin >> t->title;
    cout << "请输入工龄: ";
    cin >> t->workage;

    cout << "请输入岗位工资、薪级工资、岗位津贴、生活补贴、奖励绩效、公积金贴、逐月房贴、交通贴、应缴公积金(-)、失业险(-)、养老险(-)、职业年金(-)、医疗险(-)、工会费(-)、医互金(-)" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << "请输入第" << i + 1 << "项: ";
        cin >> t->dSalary[i];
    }

    // 计算总收入
    double total = 0;
    for (int i = 0; i < 8; i++)
    {
        total += t->dSalary[i];
    }

    for (int i = 8; i < 15; i++)
    {
        total += t->dSalary[i];
    }

    // 计算个调税和实发工资
    t->dTax = taxCount(total);
    t->lastsalary = total - t->dTax;
}

void maxMinAvg(techBook *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "没有任何职工信息，无法计算最值和平均值。" << endl;
        return;
    }

    double sum = 0;
    double salaryArray[MAX];

    // 构建工资数组
    for (int i = 0; i < abs->m_Size; i++)
    {
        salaryArray[i] = abs->personArray[i].lastsalary;
    }

    // 找最大值和最小值的迭代器
    auto maxIt = max_element(salaryArray, salaryArray + abs->m_Size);
    auto minIt = min_element(salaryArray, salaryArray + abs->m_Size);

    // 计算索引
    int maxIndex = distance(salaryArray, maxIt);
    int minIndex = distance(salaryArray, minIt);

    // 计算平均值
    for (int i = 0; i < abs->m_Size; i++)
    {
        sum += salaryArray[i];
    }
    double avg = sum / abs->m_Size;

    // 统计小于平均工资的员工数量
    int countBelowAvg = 0;
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (salaryArray[i] < avg)
        {
            countBelowAvg++;
        }
    }

    // 打印最大值、最小值及对应职工信息
    cout << "最大工资职工信息: 工号 = " << abs->personArray[maxIndex].num
         << ", 姓名 = " << abs->personArray[maxIndex].name
         << ", 实发工资 = " << abs->personArray[maxIndex].lastsalary << endl;

    cout << "最小工资职工信息: 工号 = " << abs->personArray[minIndex].num
         << ", 姓名 = " << abs->personArray[minIndex].name
         << ", 实发工资 = " << abs->personArray[minIndex].lastsalary << endl;

    // 打印平均值和小于平均工资的员工数量
    cout << "职工平均工资 = " << avg << endl;
    cout << "小于平均工资的员工人数 = " << countBelowAvg << endl;
}

// 用于依次打印工资细则
void showSalary(techBook *abs, int j)
{
    for (int i = 0; i < (sizeof(abs->personArray[0].dSalary) / sizeof(abs->personArray[0].dSalary[0])); i++)
    {
        cout << abs->personArray[j].dSalary[i] << " ";
    }
}

void showInfo(techBook *abs)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        cout << abs->personArray[i].num << "\t"
             << abs->personArray[i].name << "\t"
             << abs->personArray[i].title << "\t";
        showSalary(abs, i);
        cout << endl;
    }
}

int main()
{
    techBook abs;
    abs.m_Size = 0;
    int select = 0;
    while (select != -1)
    {
        cout << "请输入选项: 1.添加职工信息 2.显示职工信息 3.显示工资最值和平均值 (-1退出): ";
        cin >> select;
        switch (select)
        {
        case 1:
            setInfo(&abs.personArray[abs.m_Size]);
            abs.m_Size++;
            break;
        case 2:
            showInfo(&abs);
            break;
        case 3:
            maxMinAvg(&abs);
            break;
        case -1:
            cout << "欢迎下次使用" << endl;
            break;
        default:
            cout << "输入有误请重新输入" << endl;
            break;
        }
    }
    cout << endl;
    return 0;
}

double taxCount(double month_income)
{
    double rate;

    if (month_income <= 5000)
    {
        return 0;
    }
    else if (month_income <= 8000)
    {
        rate = 0.03;
        return (month_income - 5000) * rate;
    }
    else if (month_income <= 17000)
    {
        rate = 0.1;
        return (month_income - 5000) * rate;
    }
    else if (month_income <= 30000)
    {
        rate = 0.2;
        return (month_income - 5000) * rate;
    }
    else if (month_income <= 40000)
    {
        rate = 0.25;
        return (month_income - 5000) * rate;
    }
    else if (month_income <= 60000)
    {
        rate = 0.3;
        return (month_income - 5000) * rate;
    }
    else if (month_income <= 85000)
    {
        rate = 0.35;
        return (month_income - 5000) * rate;
    }
    else
    {
        rate = 0.45;
        return (month_income - 5000) * rate;
    }
}
