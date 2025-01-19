#include <algorithm>
#include <cstdlib>
#include <fstream>
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

// 保存数据到 source.txt
void saveToFile(techBook *abs, const string &filename)
{
    ofstream outFile(filename, ios::out); // 打开文件输出模式
    if (!outFile)
    {
        cerr << "无法打开文件进行写入！" << endl;
        return;
    }

    // 写入所有员工数据
    outFile << abs->m_Size << endl; // 写入当前记录数
    for (int i = 0; i < abs->m_Size; i++)
    {
        outFile << abs->personArray[i].num << " "
                << abs->personArray[i].name << " "
                << abs->personArray[i].title << " "
                << abs->personArray[i].workage << " ";
        for (int j = 0; j < 15; j++)
        {
            outFile << abs->personArray[i].dSalary[j] << " ";
        }
        outFile << abs->personArray[i].dTax << " "
                << abs->personArray[i].lastsalary << endl;
    }

    outFile.close();
    cout << "数据已成功保存到 " << filename << " 文件中。" << endl;
}

// 加载source.txt中的文件
void loadFromFile(techBook *abs, const string &filename)
{
    ifstream inFile(filename, ios::in); // 打开文件用于读取
    if (!inFile)
    {
        cerr << "文件不存在，或无法打开！程序将从空数据开始运行。" << endl;
        abs->m_Size = 0; // 如果文件不存在，初始化为空
        return;
    }

    // 读取员工数据
    inFile >> abs->m_Size; // 读取当前记录数
    for (int i = 0; i < abs->m_Size; i++)
    {
        inFile >> abs->personArray[i].num >> abs->personArray[i].name >> abs->personArray[i].title >> abs->personArray[i].workage;
        for (int j = 0; j < 15; j++)
        {
            inFile >> abs->personArray[i].dSalary[j];
        }
        inFile >> abs->personArray[i].dTax >> abs->personArray[i].lastsalary;
    }

    inFile.close();
    cout << "数据已成功从 " << filename << " 文件中加载。" << endl;
}

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
void setInfo(techBook *abs)
{
    int total; // 录入人数
    cout << "请输入录入人数:";
    cin >> total;

    for (int i = 0; i < total; i++)
    {
        if (abs->m_Size >= MAX) // 确保不超过数组上限
        {
            cout << "人员已达到最大数量，无法继续添加。" << endl;
            break;
        }

        cout << "当前录入第" << i + 1 << "位职工的信息" << endl;
        cout << "请输入职工工号: ";
        cin >> abs->personArray[abs->m_Size].num;
        cout << "请输入姓名: ";
        cin >> abs->personArray[abs->m_Size].name;
        cout << "请输入职称: ";
        cin >> abs->personArray[abs->m_Size].title;
        cout << "请输入工龄: ";
        cin >> abs->personArray[abs->m_Size].workage;

        cout << "请输入职工的15项工资明细: " << endl;
        for (int j = 0; j < 15; j++)
        {
            cout << "请输入第" << j + 1 << "项: ";
            cin >> abs->personArray[abs->m_Size].dSalary[j];
        }

        // 计算个调税和实发工资
        calculateTaxLastsalary(&abs->personArray[abs->m_Size]);

        // 录入完成，m_Size 自增，指向下一个空位置
        abs->m_Size++;
        saveToFile(abs, "source.txt");
        system("clear");
    }

    cout << "录入完成" << endl;
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

         << "应缴公积金 \t"

         << "失业险 \t"

         << "养老险 \t"

         << "职业年金 \t"

         << "医疗险 \t"

         << "工会费\t"

         << "医互金\t"

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
    saveToFile(abs, "source.txt");
}

// 比较工号
bool compareByNum(const techinf &a, const techinf &b)
{
    return a.num < b.num;
}

// 比较姓名
bool compareByName(const techinf &a, const techinf &b)
{
    return a.name < b.name;
}

// 二分查找，根据工号查找
int binarySearchByNum(techBook *abs, const string &num)
{
    int left = 0, right = abs->m_Size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (abs->personArray[mid].num == num)
        {
            return mid; // 找到该工号
        }
        else if (abs->personArray[mid].num < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // 未找到
}

// 二分查找，根据姓名查找
int binarySearchByName(techBook *abs, const string &name)
{
    int left = 0, right = abs->m_Size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (abs->personArray[mid].name == name)
        {
            return mid; // 找到该姓名
        }
        else if (abs->personArray[mid].name < name)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // 未找到
}

// 删除信息函数
void deleteSalaryInfo(techBook *abs)
{
    int select;
    cout << "=====>1.按工号删除" << endl;
    cout << "=====>2.按姓名删除" << endl;
    cout << "=====>0.退出" << endl;
    cout << "请选择(1-2或0): ";
    cin >> select;
    switch (select)
    {
    case 1: {
        string num;
        cout << "请输入要删除的员工工号：";
        cin >> num;

        // 排序员工列表，根据工号
        sort(abs->personArray, abs->personArray + abs->m_Size, compareByNum);

        // 使用二分查找找到要删除的员工
        int index = binarySearchByNum(abs, num);
        if (index != -1)
        {
            // 删除该员工数据
            for (int i = index; i < abs->m_Size - 1; i++)
            {
                abs->personArray[i] = abs->personArray[i + 1]; // 将后面的元素向前移动
            }
            abs->m_Size--; // 数量减一
            cout << "工号 " << num << " 的员工信息已删除！" << endl;
        }
        else
        {
            cout << "未找到工号 " << num << " 的员工！" << endl;
        }
    }
    break;

    case 2: {
        string name;
        cout << "请输入要删除的员工姓名：";
        cin >> name;

        // 排序员工列表，根据姓名
        sort(abs->personArray, abs->personArray + abs->m_Size, compareByName);

        // 使用二分查找找到要删除的员工
        int index = binarySearchByName(abs, name);
        if (index != -1)
        {
            // 删除该员工数据
            for (int i = index; i < abs->m_Size - 1; i++)
            {
                abs->personArray[i] = abs->personArray[i + 1]; // 将后面的元素向前移动
            }
            abs->m_Size--; // 数量减一
            cout << "姓名为 " << name << " 的员工信息已删除！" << endl;
        }
        else
        {
            cout << "未找到姓名为 " << name << " 的员工！" << endl;
        }
    }
    break;

    case 0:
        break;

    default:
        cout << "无效的选择！" << endl;
    }
}

// 查询工资记录
void searchInfo(techBook *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前表内无数据" << endl;
        return;
    }

    int select;
    cout << "=====>1.按职工工号查询" << endl;
    cout << "=====>2.按职工姓名查询" << endl;
    cout << "=====>3.按工资范围查询" << endl;
    cout << "=====>0.退出查询" << endl;
    cout << "请选择(1-3或0)" << endl;
    cin >> select;

    switch (select)
    {
    case 1: {
        string num;
        cout << "请输入要查询的员工工号：";
        cin >> num;

        for (int i = 0; i < abs->m_Size; i++)
        {
            if (num == abs->personArray[i].num)
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
                     << "应缴公积金\t"
                     << "失业险\t"
                     << "养老险\t"
                     << "职业年金\t"
                     << "医疗险\t"
                     << "工会费\t"
                     << "医互金\t"
                     << "个调税\t"
                     << "实发工资\t" << endl;
                cout << abs->personArray[i].num << "\t" << abs->personArray[i].name
                     << "\t" << abs->personArray[i].title << "\t";

                showSalary(abs, i);

                cout << abs->personArray[i].dTax << "\t";
                cout << abs->personArray[i].lastsalary << "\t";
            }
        }
    }
    break;
    case 2: {
        string name;
        cout << "请输入要查询的员工姓名: ";
        cin >> name;
        for (int i = 0; i < abs->m_Size; i++)
        {
            if (name == abs->personArray[i].name)
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
                     << "应缴公积金\t"
                     << "失业险\t"
                     << "养老险\t"
                     << "职业年金\t"
                     << "医疗险\t"
                     << "工会费\t"
                     << "医互金\t"
                     << "个调税\t"
                     << "实发工资\t" << endl;
                cout << abs->personArray[i].num << "\t" << abs->personArray[i].name
                     << "\t" << abs->personArray[i].title << "\t";

                showSalary(abs, i);

                cout << abs->personArray[i].dTax << "\t";
                cout << abs->personArray[i].lastsalary << "\t";
            }
        }
    }
    break;
    case 3: {
        double min, max;
        cout << "请输入工资查询范围, 空格隔开: ";
        cin >> min >> max;

        int isExist = 0;
        for (int i = 0; i < abs->m_Size; i++)
        {
            if (abs->personArray[i].lastsalary >= min && abs->personArray[i].lastsalary <= max)
            {
                isExist = 1;
                break;
            }
            else
            {
                isExist = 0;
            }
        }

        if (isExist == 0)
        {
            cout << "该范围内无数据" << endl;
            return;
        }

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
             << "应缴公积金\t"
             << "失业险\t"
             << "养老险\t"
             << "职业年金\t"
             << "医疗险\t"
             << "工会费\t"
             << "医互金\t"
             << "个调税\t"
             << "实发工资\t" << endl;

        for (int i = 0; i < abs->m_Size; i++)
        {
            if (abs->personArray[i].lastsalary >= min && abs->personArray[i].lastsalary <= max)
            {
                cout << abs->personArray[i].num << "\t" << abs->personArray[i].name
                     << "\t" << abs->personArray[i].title << "\t";
                showSalary(abs, i);

                cout << abs->personArray[i].dTax << "\t";
                cout << abs->personArray[i].lastsalary << "\t";
            }
        }
    }
    break;
    case 0:
        break;
    }
}

// 修改工资记录
void editSalary(techBook *abs)
{
    int select;
    cout << "=====>1.按工号修改" << endl;
    cout << "=====>2.按姓名修改" << endl;
    cout << "=====>0.退出" << endl;
    cout << "请选择(1-2或0): ";
    cin >> select;
    switch (select)
    {
    case 1: {
        string num;
        int index = -1;
        cout << "请输入需要修改的员工工号: ";
        cin >> num;
        for (int i = 0; i < abs->m_Size; i++) // 查找该员工在数组中的索引
        {
            if (num == abs->personArray[i].num)
            {
                index = i;
                cout << "已找到该员工" << endl;
            }
        }
        // 检查是否找到员工记录
        if (index == -1)
        {
            cout << "未找到工号为 " << num << " 的员工信息，删除失败！" << endl;
            return;
        }
        cout << "请重新输入15项工资(空格隔开):";
        for (int j = 0; j < sizeof(abs->personArray[index].dSalary) / sizeof(abs->personArray[index].dSalary[0]); j++)
        {
            cout << "请输入第" << j + 1 << "项: ";
            cin >> abs->personArray[index].dSalary[j];
        }
        cout << "修改成功" << endl;
    }
    break;

    case 2: {
        string name;
        int index;
        cout << "请输入需要修改的员工姓名: ";
        cin >> name;
        for (int i = 0; i < abs->m_Size; i++) // 查找该员工在数组中的索引
        {
            if (name == abs->personArray[i].name)
            {
                index = i;
                cout << "已找到该员工" << endl;
            }
        }
        // 检查是否找到员工记录
        if (index == -1)
        {
            cout << "未找到姓名为 " << name << " 的员工信息，删除失败！" << endl;
            return;
        }
        cout << "请重新输入15项工资(空格隔开):";
        for (int j = 0; j < sizeof(abs->personArray[index].dSalary) / sizeof(abs->personArray[index].dSalary[0]); j++)
        {
            cout << "请输入第" << j + 1 << "项: ";
            cin >> abs->personArray[index].dSalary[j];
        }
        cout << "修改成功" << endl;
    }
    break;

    case 0:
        break;
    }

    saveToFile(abs, "source.txt");
}

// 根据实发工资排序
void lastSalarySort(techBook *abs)
{
    for (int i = 0; i < abs->m_Size - 1; i++)
    {
        for (int j = 0; j < abs->m_Size - i - 1; j++)
        {
            if (abs->personArray[j].lastsalary > abs->personArray[j + 1].lastsalary)
            {
                techinf temp = abs->personArray[j];
                abs->personArray[j] = abs->personArray[j + 1];
                abs->personArray[j + 1] = temp;
            }
        }
    }
    saveToFile(abs, "source.txt");
    showInfo(abs);
}

// 插入工资信息
void insertSalary(techBook *abs)
{
    // 判断表内是否已满
    if (abs->m_Size >= MAX)
    {
        cout << "无法插入，员工数量已达到最大值！" << endl;
        return;
    }

    string num;
    int index = -1; // 基准位置员工工号
    cout << "请输入插入位置后一个人的工号(如末尾插入则输入1): ";
    cin >> num;

    // 末尾插入
    if (num == "1")
    {
        cout << "请输入职工工号: ";
        cin >> abs->personArray[abs->m_Size].num;
        cout << "请输入姓名: ";
        cin >> abs->personArray[abs->m_Size].name;
        cout << "请输入职称: ";
        cin >> abs->personArray[abs->m_Size].title;
        cout << "请输入工龄: ";
        cin >> abs->personArray[abs->m_Size].workage;

        cout << "请输入职工的15项工资明细: " << endl;
        for (int j = 0; j < 15; j++)
        {
            cout << "请输入第" << j + 1 << "项: ";
            cin >> abs->personArray[abs->m_Size].dSalary[j];
        }

        // 计算个调税和实发工资
        calculateTaxLastsalary(&abs->personArray[abs->m_Size]);

        // 录入完成，m_Size 自增，指向下一个空位置
        abs->m_Size++;

        // 保存到文件
        saveToFile(abs, "source.txt");
        return;
    }

    // 获取基准位置索引
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (num == abs->personArray[i].num)
        {
            index = i;
            break;
        }
    }

    // 如果工号不存在，返回错误提示
    if (index == -1)
    {
        cout << "找不到指定的工号！插入失败。" << endl;
        return;
    }

    // 从后依次将索引之后的向后移动一位，空出索引那一项数组
    for (int i = abs->m_Size; i > index; i--)
    {
        abs->personArray[i] = abs->personArray[i - 1];
    }

    cout << "请输入职工工号: ";
    cin >> abs->personArray[index].num;
    cout << "请输入姓名: ";
    cin >> abs->personArray[index].name;
    cout << "请输入职称: ";
    cin >> abs->personArray[index].title;
    cout << "请输入工龄: ";
    cin >> abs->personArray[index].workage;

    cout << "请输入职工的15项工资明细: " << endl;
    for (int j = 0; j < 15; j++)
    {
        cout << "请输入第" << j + 1 << "项: ";
        cin >> abs->personArray[index].dSalary[j];
    }

    // 计算个调税和实发工资
    calculateTaxLastsalary(&abs->personArray[index]);

    // 录入完成，m_Size 自增，指向下一个空位置
    abs->m_Size++;

    // 保存到文件
    saveToFile(abs, "source.txt");
}

// 密码加密
string reversePassword(const string &password)
{
    string reversedPassword = password;                        // 复制密码
    reverse(reversedPassword.begin(), reversedPassword.end()); // 反转字符串
    return reversedPassword;
}

// 创建密码并保存到文件
void createPassword()
{
    string password;
    cout << "请输入新密码：";
    getline(cin, password);

    // 将密码反转并存储
    ofstream pwOut("password.txt", ios::out);
    if (pwOut.is_open())
    {
        string encryptedPassword = reversePassword(password); // 反转密码
        pwOut << encryptedPassword << endl;                   // 写入反转后的密码
        cout << "密码已创建并保存!" << endl;
    }
    else
    {
        cout << "无法打开文件!" << endl;
        return;
    }
}

// 验证输入的密码
bool verifyPassword()
{
    string inputPassword;
    getline(cin, inputPassword); // 获取用户输入的密码

    // 从文件中读取密码并反转
    ifstream pwIn("password.txt", ios::in);
    string storedPassword;
    if (getline(pwIn, storedPassword))
    {
        string decryptedPassword = reversePassword(storedPassword); // 解密反转密码
        if (decryptedPassword == inputPassword)
        {
            return true; // 验证成功
        }
    }
    else
    {
        cout << "无法读取密码文件!" << endl;
    }
    return false; // 验证失败
}

int main()
{
    // 登录
    //  检查是否已有密码文件
    ifstream pwIn("password.txt", ios::in);
    if (!pwIn.is_open())
    {
        // 如果没有密码文件，提示用户创建密码
        cout << "没有找到密码文件，创建新密码..." << endl;
        createPassword();
    }
    else
    {
        // 否则执行密码验证
        cout << "请输入密码进行登录：";
        if (verifyPassword())
        {
            cout << "登录成功!" << endl;
        }
        else
        {
            cout << "密码错误!" << endl;
            return 0;
        }
    }

    // 管理系统
    techBook abs;
    abs.m_Size = 0;
    // 从文件加载数据
    loadFromFile(&abs, "source.txt");
    int quit = 1;
    while (quit != 0)
    {
        int select;
        cout << "*************************工资管理系统***************************" << endl;
        cout << "*****************************菜单******************************" << endl;
        cout << "1、录入工资(批量)          2、删除工资记录" << endl;
        cout << "3、查询工资记录            4、修改工资记录" << endl;
        cout << "5、插入工资(单条)          6、统计分析" << endl;
        cout << "7、工资记录排序		    8、调整工资" << endl;
        cout << "9、显示工资记录            0、退出管理系统" << endl;
        cout << "****************************************************************" << endl;
        cout << "************************* 请选择0-9: ****************************" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            setInfo(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();       // 确保回车操作被捕获
            system("clear"); // 清除(此处针对于macos系统，windows中clear替换成cls即可)
            break;
        case 2:
            deleteSalaryInfo(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 3:
            searchInfo(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 4:
            editSalary(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 5:
            insertSalary(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 6:
            maxMinAvg(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 7:
            lastSalarySort(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 8:
            maxMinAvg(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 9:
            showInfo(&abs);
            cout << "按回车返回菜单" << endl;
            cin.get();
            cin.get();
            system("clear");
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            saveToFile(&abs, "source.txt"); // 保存数据到文件
            quit = 0;
            break;
        }
    }
}
