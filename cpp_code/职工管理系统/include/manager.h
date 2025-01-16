#pragma once
#include "worker.h"
#include <iostream>

using namespace std;

class Manager : public Worker
{
  public:
    // 构造函数
    Manager(int id, string name, int depId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};