#include "speechManager.h"
#include "speaker.h"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <utility>
#include <vector>
using namespace std;

SpeechManager::SpeechManager()
{
    // 初始化容器和属性
    this->initSpeech();

    this->createSpeaker();

    // 加载往届记录
    this->loadRecord();
}

// 菜单功能
void SpeechManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechManager::screenClear() // 清屏操作
{
#ifdef _WIN32
    system("cls");
#else
    cout << "按回车继续...";
    cin.get();
    system("clear");
#endif
}

// 退出
void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    cin.get();
    cout << "按回车继续..." << endl;
    cin.get();
    exit(0);
}

// 初始化容器和属性
void SpeechManager::initSpeech()
{
    // 容器都置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    // 初始化比赛轮数
    this->m_Index = 1;
}

// 创建选手
void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";

    for (int i = 0; i < nameSeed.size(); i++)
    {
        Speaker sp;
        sp.m_Name = "选手";
        sp.m_Name += nameSeed[i];
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }
        // 12名选手编号
        this->v1.push_back(i + 10001);
        // 选手编号以及对应的选手存放到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

// 抽签函数
void SpeechManager::speechDraw()
{
    cout << "第 " << this->m_Index << " 轮比赛选手正在抽签" << endl;
    cout << "--------------------" << endl;
    cout << "抽签后演讲顺序如下: " << endl;

    random_device rd;
    mt19937 g(rd());

    if (this->m_Index == 1)
    {
        // 第一轮比赛
        shuffle(v1.begin(), v1.end(), g);
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        // 第二轮比赛
        shuffle(v2.begin(), v2.end(), g);
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
    cin.get();
    cin.get();
    cout << endl;
}

// 比赛
void SpeechManager::speechContest()
{
    cout << "----------第 " << this->m_Index << " 轮比赛正式开始----------" << endl;

    // 准备临时容器存放小组成绩
    multimap<double, int, greater<double>> groupScore;
    int num = 0; // 记录人员 6人一组

    vector<int> v_Src; // 比赛选手容器
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    // 遍历所有选手进行比赛
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++; // 表中人数递增
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            // cout << score << " "; 测试
            d.push_back(score);
        }
        // cout << endl;

        sort(d.begin(), d.end(), greater<double>()); // 降序
        d.pop_front();                               // 去掉最高分和最低分
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f); // 起始值0.0f 小数 总分
        double avg = sum / (double)d.size();               // 强制为小数 平均分

        // cout << "编号: " << *it << " 姓名: " << this->m_Speaker[*it].m_Name << " avg = " << avg << endl;

        // 将平均分放入map容器中
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg; //*it是map容器的key，index-1表示存储的第一轮的分数

        // 将打分数据 放入到临时小组容器中
        groupScore.insert(make_pair(avg, *it)); // key是得分，value是具体选手编号

        // 分组并打印成绩
        if (num % 6 == 0)
        {
            cout << "第 " << num / 6 << " 小组比赛名次: " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号: " << it->second << " 姓名: " << this->m_Speaker[it->second].m_Name << " 成绩: " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }

            // 取走前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }
            }

            // 前六个人信息输出完毕，清空容器，供后六个人存储
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "----------第 " << this->m_Index << " 轮比赛完毕----------" << endl;
}

// 显示得分
void SpeechManager::showScore()
{
    cout << "----------第 " << this->m_Index << " 轮晋级选手信息如下----------" << endl;
    vector<int> v;
    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号：" << *it << " 姓名： " << m_Speaker[*it].m_Name << " 得分： " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;

    cin.get();
    this->screenClear();
    this->showMenu();
}

// 保存记录
void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 追加方式写文件
    // 将每个选手的数据写入到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "记录已保存" << endl;
}

// 读取记录
void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv");

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "文件打开失败" << endl;
        ifs.close();
        this->screenClear();
        return;
    }

    // 文件清空情况
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        this->fileIsEmpty = true;
        return;
    }

    // 文件不为空
    this->fileIsEmpty = false;
    ifs.putback(ch); // 将上面读到的单个字符放回去
    string data;
    while (ifs >> data)
    {
        // cout << data << endl;
        int pos = -1; // 查找到逗号的位置的变量
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                // 没有找到的情况
                break;
            }
            string temp = data.substr(start, pos - start);
            cout << temp << endl;

            start = pos + 1;
        }
    }
    ifs.close();
    cin.get();
    this->screenClear();
}

// 开始比赛 整个比赛流程控制函数
void SpeechManager::startSpeech()
{
    // 第一轮比赛
    // 1、抽签

    // 抽签函数
    this->speechDraw();
    // 2、比赛
    this->speechContest();
    // 3、显示晋级结果
    this->showScore();
    // 第二轮比赛
    this->m_Index++;
    // 1、抽签
    this->speechDraw();
    // 2、比赛
    this->speechContest();
    // 3、显示最终结果
    this->showScore();
    // 4、保存分数
    this->saveRecord();

    cout << "本届比赛完毕" << endl;
    cin.get();
    this->screenClear();
}

SpeechManager::~SpeechManager()
{
}