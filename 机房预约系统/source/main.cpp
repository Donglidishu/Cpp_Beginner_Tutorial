#include "Identity.h"
#include "globalFile.h"
#include "screenClear.h"
#include <fstream>
#include <iostream>
using namespace std;

// 登录功能 参数1 操作文件名 操作2 操作身份类别
void LoginIn(string fileName, int type)
{
    // 父类指针 用于指向子类对象
    Identity *person = nullptr;

    // 读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    // 判断文件是否存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 准备接受用户的信息
    int id = 0;
    string name;
    string pwd;

    // 判断身份
    if (type == 1) // 学生身份
    {
        cout << "请输入你的学号: " << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入你的职工号: " << endl;
        cin >> id;
    }
    cout << "请输入用户名: " << endl;
    cin >> name;

    cout << "请输入密码: " << endl;
    cin >> pwd;

    if (type == 1)
    {
        // 学生身份验证
    }
    else if (type == 2)
    {
        // 教师身份验证
    }
    else if (type == 3)
    {
        // 管理员身份验证
    }
    cout << "登录验证失败" << endl;
    cin.get();
    screenClear();
    return;
}

int main()
{
    int select = 0;

    while (true)
    {
        cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select;
        switch (select)
        {
        case 1: // 学生
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2: // 老师
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3: // 管理员
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0: // 退出系统
            cout << "欢迎下次使用" << endl;
            cin.get();
            return 0;
            break;
        default:
            cout << "输入有误，请重新选择" << endl;
            cin.get();
            screenClear();
            break;
        }
    }
    return 0;
}