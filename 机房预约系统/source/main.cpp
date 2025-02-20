#include "Identity.h"
#include "Manager.h"
#include "Student.h"
#include "Teacher.h"
#include "globalFile.h"
#include "screenClear.h"
#include <fstream>
#include <iostream>
using namespace std;

// 进入老师子菜单界面
void teacherMenu(Identity *&teacher)
{
    while (true)
    {
        // 教师菜单
        teacher->operMenu();

        Teacher *tea = (Teacher *)teacher;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            // 查看所有预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            // 审核预约
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;
            cin.get();
            screenClear();
            return;
        }
    }
}

// 进入管理员子菜单界面
void managerMenu(Identity *&manager)
{
    while (true)
    {
        // 调用管理员子菜单
        manager->operMenu();

        Manager *man = (Manager *)manager;

        int select = 0;
        cin >> select;
        if (select == 1) // 添加账号
        {
            man->addPerson();
        }
        else if (select == 2) // 查看账号
        {
            man->showPerson();
        }
        else if (select == 3) // 查看机房
        {
            man->showComputer();
        }
        else if (select == 4) // 清空预约
        {
            man->cleanFile();
        }
        else
        {
            delete manager;
            cout << "注销成功" << endl;
            cin.get();
            screenClear();
            return;
        }
    }
}

// 学生子菜单
void studentMenu(Identity *&student)
{
    while (true)
    {
        student->operMenu();
        Student *stu = (Student *)student;
        int select = 0;

        cin >> select;

        if (select == 1) // 申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2) // 查看自身预约
        {
            stu->showOrder();
        }
        else if (select == 3) // 查看所有预约
        {
            stu->showAllOrder();
        }
        else if (select == 4) // 取消预约
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout << "注销成功" << endl;
            cin.get();
            screenClear();
            return;
        }
    }
}

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
        int fId;      // 从文件中读取的id号
        string fName; // 从文件中读取的姓名
        string fPwd;  // 从文件中读取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            // cout << fId << " " << fName << " " << fPwd << endl;
            // 与用户输入的信息作对比
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "学生验证登录成功" << endl;
                cin.get();
                screenClear();
                person = new Student(id, name, pwd); // 多态 创建学生对象
                // 进入学生子菜单
                studentMenu(person);
                return;
            }
        }
    }
    else if (type == 2)
    {
        // 教师身份验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师验证登录成功" << endl;
                cin.get();
                screenClear();
                person = new Teacher(id, name, pwd);
                // 进入老师子菜单
                // 进入教师子菜单
                teacherMenu(person);

                return;
            }
        }
    }
    else if (type == 3)
    {
        // 管理员身份验证
        // 管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                cout << "验证登录成功" << endl;
                // 登录成功后，按任意键进入管理员界面
                cin.get();
                screenClear();
                // 创建管理员对象
                person = new Manager(name, pwd);

                // 管理员菜单
                managerMenu(person);

                return;
            }
        }
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