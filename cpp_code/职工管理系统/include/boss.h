#pragma once
#include "worker.h"
#include <iostream>
#include <string>

using namespace std;

class Boss : public Worker
{
  public:
    // 构造函数
    Boss(int id, string name, int depId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};