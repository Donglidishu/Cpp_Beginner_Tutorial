#pragma once
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include <iostream>
using namespace std;

class WorkerManager
{

  public:
    // 构造函数
    WorkerManager();

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

    // 析构函数
    ~WorkerManager();
};
