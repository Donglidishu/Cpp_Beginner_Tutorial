#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include "workerManager.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 测试代码
    // Worker *worker1 = new Employee(1, "xzk", 111);
    // worker1->showInfo();
    // delete worker1;

    // Worker *worker2 = new Employee(2, "xzk", 111);
    // worker2->showInfo();
    // delete worker2;

    // Worker *worker3 = new Employee(3, "xzk", 111);
    // worker3->showInfo();
    // delete worker3;

    // 实例化管理者对象
    WorkerManager wm;

    // 调用展示菜单的成员函数
    int choice = 0;
    while (true)
    {
        // 展示菜单
        wm.showMenu();
        cout << "请输入您的选择:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: // 退出系统
            wm.exitSystem();
            break;
        case 1: // 添加职工
            wm.addEmp();
            break;
        case 2: // 显示职工
            wm.show_Emp();
            break;
        case 3: // 删除职工
            wm.del_Emp();
            break;
        case 4: // 修改职工
            wm.modEmp();
            break;
        case 5: // 查找职工
            wm.find_Emp();
            break;
        case 6: // 排序职工
            break;
        case 7: // 清空文件
            break;
        default:
            system("clear");
            break;
        }
    }

    return 0;
}
