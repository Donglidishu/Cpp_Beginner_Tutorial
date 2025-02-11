#pragma once

#include <string>
using namespace std;

// 身份抽象基类
class Identity
{
  public:
    // 操作菜单纯虚函数
    virtual void operMenu() = 0;

    virtual ~Identity() = 0;

  public:
    // 用户名及密码
    string m_Name;
    string m_Pwd;
};