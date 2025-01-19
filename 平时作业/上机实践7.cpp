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
    int m_Size; // 记录表中人数
};

// 计算个调税
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

// 计算个调税和实发工资，从setinfo中脱离出便于在调整工资之后重新计算
void calculateTaxLastsalary(techinf *t)
{
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
    t->dTax = taxCount(total);       // 个调税
    t->lastsalary = total - t->dTax; // 实发工资
}

// 设置员工信息
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

    calculateTaxLastsalary(t); // 计算个调税和实发工资
}

// 求最大最小和平均值
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

// 用于依次打印工资细则，与showInfo配合
void showSalary(techBook *abs, int j)
{
    for (int i = 0; i < (sizeof(abs->personArray[0].dSalary) / sizeof(abs->personArray[0].dSalary[0])); i++)
    {
        cout << abs->personArray[j].dSalary[i] << "\t";
    }
}

// 显示信息
void showInfo(techBook *abs)
{
    cout << "工号\t"
         << "姓名\t"
         << "职称\t"
         << "岗位工资\t"
         << "薪级工资\t"
         << "岗位津贴\t"
         << "生活补贴\t"
         << "奖励绩效\t"
         << "公积金贴\t"
         << "逐月房贴\t"
         << "交通贴\t"
         << "应缴公积金(-)\t"
         << "失业险(-)\t"
         << "养老险(-)\t"
         << "职业年金(-)\t"
         << "医疗险(-)\t"
         << "工会费(-)\t"
         << "医互金(-)\t"
         << "个调税\t"
         << "实发工资\t" << endl;
    for (int i = 0; i < abs->m_Size; i++)
    {
        cout << abs->personArray[i].num << "\t"
             << abs->personArray[i].name << "\t"
             << abs->personArray[i].title << "\t";
        showSalary(abs, i);
        cout << abs->personArray[i].dTax << "\t";
        cout << abs->personArray[i].lastsalary << "\t";
    }
}

// 调整工资
void adjustSalary(techBook *abs)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 按职称调整岗位工资
        if (abs->personArray[i].title == "教授")
        {
            abs->personArray[i].dSalary[0] *= 1.1;
        }
        else if (abs->personArray[i].title == "副教授")
        {
            abs->personArray[i].dSalary[0] *= 1.08;
        }
        else if (abs->personArray[i].title == "讲师")
        {
            abs->personArray[i].dSalary[0] *= 1.05;
        }
        else if (abs->personArray[i].title == "初级")
        {
            abs->personArray[i].dSalary[0] *= 1.04;
        }
        else if (abs->personArray[i].title == "其他")
        {
            abs->personArray[i].dSalary[0] *= 1.03;
        }

        // 按工作时间调整薪级工资
        if (abs->personArray[i].workage >= 25)
        {
            abs->personArray[i].dSalary[1] += 60;
        }
        else if (abs->personArray[i].workage > 20)
        {
            abs->personArray[i].dSalary[1] += 55;
        }
        else if (abs->personArray[i].workage > 15)
        {
            abs->personArray[i].dSalary[1] += 50;
        }
        else if (abs->personArray[i].workage > 10)
        {
            abs->personArray[i].dSalary[1] += 45;
        }
        else if (abs->personArray[i].workage >= 1)
        {
            abs->personArray[i].dSalary[1] += 40;
        }

        calculateTaxLastsalary(&abs->personArray[i]); // 重新计算个调税和实发工资
    }
}

// 递归计算指定人第n年岗位工资函数
double caculateNSalary(double salary, int n, string title)
{
    double rate;
    if (n == 1)
    {
        return salary;
    }
    if (title == "教授")
    {
        rate = 1.1;
    }
    else if (title == "副教授")
    {
        rate = 1.08;
    }
    else if (title == "讲师")
    {
        rate = 1.05;
    }
    else if (title == "初级")
    {
        rate = 1.04;
    }
    else if (title == "其他")
    {
        rate = 1.03;
    }
    return caculateNSalary(salary, n - 1, title) * rate;
}

// 查询指定员工第n年岗位工资
void searchSalary(techBook *abs)
{
    string idIn;
    int yearIn;
    double salaryTemp; // 存放从表中查询到的员工的岗位工资
    string titleTemp;  // 存放查询到的职称
    string nameTemp;   // 存放姓名
    cout << "请输入工号: ";
    cin >> idIn;
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].num == idIn)
        {
            salaryTemp = abs->personArray[i].dSalary[0];
            titleTemp = abs->personArray[i].title;
            nameTemp = abs->personArray[i].name;
        }
    }
    cout << "请输入要查询第几年的工资: ";
    cin >> yearIn;

    double finalSalary = caculateNSalary(salaryTemp, yearIn, titleTemp);
    cout << nameTemp << "的第" << yearIn << "年岗位工资为" << finalSalary << endl;
}

// 计算两个日期之间相差的月份数
int calculateMonthDifference(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay)
{
    // 年份差转为月份差 + 月份差
    int totalMonths = (endYear - startYear) * 12 + (endMonth - startMonth);

    // 根据日期判断是否减去一个月
    if (endDay < startDay)
    {
        totalMonths -= 1;
    }

    return totalMonths;
}

// 应补发工资
void backPay(techBook *abs)
{
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    double lastSalaryTemp[MAX];
    double backPayTemp[MAX];

    cout << "请输入起始日期 (格式: 年 月 日): ";
    cin >> startYear >> startMonth >> startDay;

    cout << "请输入结束日期 (格式: 年 月 日): ";
    cin >> endYear >> endMonth >> endDay;

    // 调用工作时长月份计算函数计算月份
    int months = calculateMonthDifference(startYear, startMonth, startDay, endYear, endMonth, endDay);

    showInfo(abs);

    for (int i = 0; i < abs->m_Size; i++)
    {
        lastSalaryTemp[i] = abs->personArray[i].lastsalary;
    }
    adjustSalary(abs); // 重新计算调整后工资

    for (int i = 0; i < abs->m_Size; i++)
    {
        backPayTemp[i] = abs->personArray[i].lastsalary - lastSalaryTemp[i];
    }

    // 输出结果
    cout << "补发工资: " << endl;
    cout << "工号\t" << "姓名\t" << "补发工资\t" << endl;
    for (int i = 0; i < abs->m_Size; i++)
    {
        cout << abs->personArray[i].num << "\t"
             << abs->personArray[i].name << "\t"
             << backPayTemp[i] * months << endl;
    }
}

// 调整薪资菜单
void adjustSalaryMenu(techBook *abs)
{
    int select;
    while (select != 0)
    {
        cout << "-----------------------------------------" << endl;
        cout << "1 工资调整" << endl;
        cout << "2 查询指定职工的工资" << endl;
        cout << "3 应补发工资" << endl;
        cout << "0 退出" << endl;
        cout << "-----------------------------------------" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            adjustSalary(abs);
            showInfo(abs);
            break;
        case 2:
            searchSalary(abs);
            break;
        case 3:
            backPay(abs);
            break;
        case 0:
            break;
        }
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
            break;
        default:
            cout << "输入有误请重新输入" << endl;
            break;
        }
        cout << endl;
    }

    adjustSalaryMenu(&abs);
    return 0;
}
