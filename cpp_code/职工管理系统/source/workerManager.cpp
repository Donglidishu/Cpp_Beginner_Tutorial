#include "workerManager.h"

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
    }
    else
    {
        cout << "输入有误" << endl;
    }
}

WorkerManager::~WorkerManager()
{
}
