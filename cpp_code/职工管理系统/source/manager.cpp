#include "manager.h"
#include <string>

using namespace std;

// 经理类
Manager::Manager(int id, string name, int depId)
{
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = depId;
}

void Manager::showInfo()
{
    cout << "职工编号: " << this->m_ID
         << "\t职工姓名: " << this->m_Name
         << "\t岗位: " << this->getDeptName()
         << "\t岗位职责: 完成老板交给的任务，并下发任务给普通员工" << endl;
}

string Manager::getDeptName()
{
    return string("经理");
}