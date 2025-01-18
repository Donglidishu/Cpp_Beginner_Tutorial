#pragma once
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include <fstream>
#include <iostream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{

  public:
    // 构造函数
    WorkerManager();

    // 清屏函数
    void screenClean();

    // 展示菜单
    void showMenu();

    // 退出函数
    void exitSystem();

    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker **m_EmpArray;

    // 添加职工函数
    void addEmp();

    // 保存到文件函数
    void save();

    // 判断文件是否为空状态
    bool m_FileIsEmpty;

    // 统计文件中人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示员工信息
    void show_Emp();

    // 删除员工信息
    void del_Emp();

    // 判断员工是否存在,找到返回index，否则返回-1
    int isExist(int id);

    // 修改员工信息
    void modEmp();

    // 查找员工信息
    void find_Emp();

    // 析构函数
    ~WorkerManager();
};
