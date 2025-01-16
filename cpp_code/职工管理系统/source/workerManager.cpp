#include "workerManager.h"
#include "boss.h"
#include "manager.h"
#include <cstdlib>

WorkerManager::WorkerManager()
{
    // 初始化属性
    this->m_EmpNum = 0;
    this->m_EmpArray = nullptr;
}

// 菜单函数
void WorkerManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// 退出函数
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkerManager::addEmp()
{
    int addNum = 0; // 保存用户输入的数量
    cout << "请输入添加的职工的数量: ";
    cin >> addNum;

    if (addNum > 0)
    {
        // 添加
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间大小 = 原来记录人数 + 新增人数

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];

        // 将原来内存中的数据拷贝到新内存中
        if (this->m_EmpArray != nullptr)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;      // 职工编号
            string name; // 职工姓名
            int dSelect; // 部门选择

            cout << "请输入第 " << i + 1 << " 个新职工的编号: ";
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个新职工的姓名: ";
            cin >> name;
            cout << "请选择该职工的岗位: " << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker *worker = nullptr;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            // 将创建的职工指针保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }
        // 释放原有内存
        delete[] this->m_EmpArray;

        // 更改新内存空间的指向
        this->m_EmpArray = newSpace;

        // 更新职工人数
        this->m_EmpNum = newSize;

        cout << "成功添加了 " << addNum << " 名新职工信息" << endl;
    }
    else
    {
        cout << "输入有误" << endl;
    }

    // 按回车继续
    cin.get();
    cin.get();
    // 清屏
    system("clear");
}

WorkerManager::~WorkerManager()
{
}
