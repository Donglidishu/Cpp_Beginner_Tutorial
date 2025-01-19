#include "workerManager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

WorkerManager::WorkerManager()
{
    ifstream ifs;
    // 1.文件不存在
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "未找到文件，重新创建" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        // 初始化文件为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 2.文件为空，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // 文件为空
        cout << "文件为空" << endl;
        // 初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = nullptr;
        // 初始化文件为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 3.文件存在，并且记录数据
    int num = this->get_EmpNum();
    cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;

    // 开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 将文件中的数据存到数组中
    this->init_Emp();

    // //测试代码
    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << "职工号： " << this->m_EmpArray[i]->m_ID
    //          << " 职工姓名： " << this->m_EmpArray[i]->m_Name
    //          << " 部门编号： " << this->m_EmpArray[i]->m_DeptID << endl;
    // }
}

// 清屏函数
void WorkerManager::screenClean()
{
    cin.get();
    cout << "按回车继续..." << endl;
    cin.get();
    system("clear");
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

        // 更新职工不为空标志
        this->m_FileIsEmpty = false;

        // 保存到文件
        this->save();

        cout << "成功添加了 " << addNum << " 名新职工信息" << endl;
    }
    else
    {
        cout << "输入有误" << endl;
    }

    this->screenClean();

    // 清屏
    system("clear");
}

// 保存文件函数
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_ID << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptID << endl;
    }
    ofs.close();
}

// 统计文件中人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        // 统计人数变量
        num++;
    }
    return num;
}

// 初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = nullptr;
        if (dId == 1) // 普通员工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) // 经理
        {
            worker = new Manager(id, name, dId);
        }
        else if (dId == 3) // 老板
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

    // 关闭文件
    ifs.close();
}

// 展示员工信息
void WorkerManager::show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            // 利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    this->screenClean();
}

// 删除员工信息
void WorkerManager::del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        // 按照职工编号删除
        cout << "请输入想要删除的职工编号: ";
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            // 数据迁移
            for (int i = 0; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--; // 更新数组中记录人员的个数
            // 数据同步更新到文件中
            this->save();
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
        if (this->m_EmpNum == 0) // 更新 m_FileIsEmpty 状态
        {
            this->m_FileIsEmpty = true;
        }
    }

    this->screenClean();

    system("clear");
}

// 判断员工是否存在,找到返回index，否则返回-1
int WorkerManager::isExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_ID == id)
        {
            // 找到员工
            index = i;

            break;
        }
    }
    return index;
}

// 修改员工信息
void WorkerManager::modEmp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或数据为空" << endl;
    }
    else
    {
        cout << "请输入要修改的员工的编号: ";
        int id;
        cin >> id;

        int ret = isExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId;
            string newName;
            int dSelect;
            cout << "请输入新的员工编号: ";
            cin >> newId;
            cout << "请输入新的员工姓名: ";
            cin >> newName;

            cout << "请选择新职工的岗位: " << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;
            Worker *worker = nullptr;

            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, 1);
                break;
            case 2:
                worker = new Manager(newId, newName, 2);
                break;
            case 3:
                worker = new Boss(newId, newName, 3);
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = worker;

            // 保存到文件
            this->save();

            cout << "修改成功" << endl;
        }
        else
        {
            cout << "查无此人" << endl;
        }
    }
    this->screenClean();
}

// 查找员工信息
void WorkerManager::find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者数据为空" << endl;
    }
    else
    {
        cout << "请输入查找方式: " << endl;
        cout << "1.按编号查找" << endl;
        cout << "2.按姓名查找" << endl;
        int select;
        cin >> select;
        if (select == 1)
        {
            cout << "请输入要查找的员工的编号: ";
            int idSearch;
            cin >> idSearch;

            int ret = this->isExist(idSearch);
            if (ret != -1)
            {
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查无此人" << endl;
            }
        }
        else if (select == 2)
        {
            cout << "请输入要查找的员工的姓名: ";
            string nameSearch;
            cin >> nameSearch;

            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == nameSearch)
                {
                    cout << "查找到职工编号为 " << this->m_EmpArray[i]->m_ID << " 的职工 信息如下: " << endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "查无此人" << endl;
            }
        }
        else
        {
            cout << "输入有误" << endl;
        }
    }
    this->screenClean();
}

// 按照编号排序
void WorkerManager::sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
        this->screenClean();
    }
    else
    {
        cout << "请选择排序方式: " << endl;
        cout << "1.按职工编号升序" << endl;
        cout << "2.按职工编号降序" << endl;

        int select = 0;
        cin >> select;
        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i; // 声明最小值 或 最大值下标
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (select == 1)
                {
                    if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
                else
                {
                    if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
            }
            // 判断一开始认定的最小值或最大值是不是内层循环计算出的最大值或最小值，如果不是，则交换数据
            if (minOrMax != i)
            {
                Worker *temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }
        this->save();
        cout << "排序成功 排序后的结果为: " << endl;
        this->show_Emp();
    }
}

// 清空文件
void WorkerManager::clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc); // ios::trunc截断模式，如果文件存在，则清空文件内容; 如果文件不存在，则创建空白文件
        ofs.close();

        if (this->m_EmpArray != nullptr)
        {
            // 删除堆区的每个职工对象
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = nullptr;
            }
            // 删除堆区的数组指针
            delete[] this->m_EmpArray;
            this->m_EmpArray = nullptr;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功" << endl;
        this->screenClean();
    }
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != nullptr)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}
