#pragma once

#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "computerRoom.h"
#include <vector>

using namespace std;

class Manager : public Identity
{
  public:
    // 默认构造
    Manager();

    // 有参构造  管理员姓名，密码
    Manager(string name, string pwd);

    // 选择菜单
    virtual void operMenu();

    // 添加账号
    void addPerson();

    // 查看账号
    void showPerson();

    // 查看机房信息
    void showComputer();

    // 清空预约记录
    void cleanFile();

    // 初始化去重容器
    void initVector();

    // 检查是否有重复
    bool checkRepeat(int id, int type);

    // 学生容器
    vector<Student> vStudent;

    // 教师容器
    vector<Teacher> vTeacher;

    // 机房信息容器
    vector<ComputerRoom> vCom;

    ~Manager();
};