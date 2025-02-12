#include "Manager.h"
#include "Student.h"
#include "Teacher.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "screenClear.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 默认构造
Manager::Manager()
{
}

// 有参构造
Manager::Manager(string name, string pwd)
{
    // 初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 初始化容器
    this->initVector();

    // 初始化机房信息容器
    ifstream ifs;

    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxCap)
    {
        vCom.push_back(c);
    }
    cout << "当前机房数量为: " << vCom.size() << endl;
    ifs.close();
}

// 选择菜单
void Manager::operMenu()
{
    cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

// 添加账号
void Manager::addPerson()
{
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    string errTip; // 错误提示，用户id重复时的提醒
    ofstream ofs;

    int select = 0;
    cin >> select;
    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号: ";
        errTip = "学号重复，请重新输入";
    }
    else
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号: ";
        errTip = "职工编号重复，请重新输入: ";
    }

    ofs.open(fileName, ios::out | ios::app); // app 追加模式 追加内容到末尾
    int id;
    string name;
    string pwd;
    cout << tip << endl;
    while (true)
    {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret)
        {
            cout << errTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名： " << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    this->initVector(); // 更新容器中的信息

    cin.get();
    screenClear();

    ofs.close();
}

void printStudent(Student &s)
{
    cout << "学号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher &t)
{
    cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

// 查看账号
void Manager::showPerson()
{
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0;

    cin >> select;
    if (select == 1)
    {
        cout << "所有学生信息如下: " << endl;
        for_each(vStudent.begin(), vStudent.end(), printStudent);
    }
    else
    {
        cout << "所有老师信息如下: " << endl;
        for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
    }

    cin.get();
    screenClear();
}

// 查看机房信息
void Manager::showComputer()
{
    cout << "机房信息如下: " << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "机房编号: " << it->m_ComId << " 最大容量: " << it->m_MaxCap << endl;
    }
    cin.get();
    screenClear();
}

// 清空预约记录
void Manager::cleanFile()
{
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);

    cout << "清空成功" << endl;
    cin.get();
    screenClear();
}

// 初始化容器
void Manager::initVector()
{
    ifstream ifs;
    // 清空两个容器
    vStudent.clear();
    vTeacher.clear();

    // 学生容器初始化
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 将读取到的信息放入容器
    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStudent.push_back(s);
    }
    cout << "当前学生数量为 " << vStudent.size() << endl;
    ifs.close();

    // 教师容器初始化
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTeacher.push_back(t);
    }
    cout << "当前教师数量为 " << vTeacher.size() << endl;
    ifs.close();
}

// 检查是否有重复
bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
        {
            if (it->m_Id == id)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
        {
            if (it->m_EmpId == id)
            {
                return true;
            }
        }
    }
    return false;
}

Manager::~Manager()
{
}