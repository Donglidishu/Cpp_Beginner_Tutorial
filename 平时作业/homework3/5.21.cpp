#include <iostream>
using namespace std;

void jingli()
{
    int gongzi = 0, weeks = 0;
    cout << "请输入经理每周工资: ";
    cin >> gongzi;
    cout << "请输入工作周数: " << endl;
    cin >> weeks;
    cout << "薪资为: " << gongzi * weeks;
    cout << endl;
}

void xiaoshigong()
{
    int hours, gongzi;
    cout << "请输入小时工资: ";
    cin >> gongzi;
    cout << "请输入工作小时数: ";
    cin >> hours;
    if (hours <= 40)
    {
        cout << "薪资为: " << gongzi * hours << endl;
        cout << endl;
    }
    else if (hours > 40)
    {
        cout << "薪资为: " << (gongzi - 40) * hours * 1.5 + gongzi * 40 << endl;
        cout << endl;
    }
}

void yongjingong()
{
    double interest;
    cout << "请输入销售毛利: ";
    cin >> interest;
    cout << "薪资为: " << 250 + interest * 0.057 << endl;
    cout << endl;
}

void jijiangong()
{
    int jianshu, price;
    cout << "请输入制作个数: ";
    cin >> jianshu;
    cout << "请输入每个工件的单价: ";
    cin >> price;
    cout << "薪资为: " << jianshu * price << endl;
    cout << endl;
}

int main()
{
    int select;
    while (select != -1)
    {
        cout << "请选择需要计算薪资的工种: 1.经理 2.小时工 3.佣金工 4.计件工 (-1退出) ";
        cin >> select;
        switch (select)
        {
        case 1:
            jingli();
            break;
        case 2:
            xiaoshigong();
            break;
        case 3:
            yongjingong();
            break;
        case 4:
            jijiangong();
            break;
        case -1:
            cout << "欢迎下次使用" << endl;
            break;
        default:
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }

    return 0;
}