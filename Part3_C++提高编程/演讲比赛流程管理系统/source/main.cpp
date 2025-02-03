#include "speaker.h"
#include "speechManager.h"
#include <ios>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    // 创建管理类对象
    SpeechManager Manager;

    // 测试12名选手创建
    for (map<int, Speaker>::iterator it = Manager.m_Speaker.begin(); it != Manager.m_Speaker.end(); it++)
    {
        cout << "编号: " << (*it).first << " 姓名: " << (*it).second.m_Name << " 分数: " << (*it).second.m_Score[0] << endl;
    }

    while (true)
    {
        Manager.showMenu();
        int select = 0;
        cout << "请输入您的选择: ";
        cin >> select;

        // 检查cin是否处于错误状态
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃错误输入
            Manager.screenClear();
            continue;
        }

        switch (select)
        {
        case 1: // 开始比赛
            Manager.startSpeech();
            break;
        case 2: // 查看往届记录
            break;
        case 3: // 清空比赛记录
            break;
        case 0: // 退出系统
            Manager.exitSystem();
            break;
        default:
            Manager.screenClear(); // 清屏
            break;
        }
    }

    return 0;
}