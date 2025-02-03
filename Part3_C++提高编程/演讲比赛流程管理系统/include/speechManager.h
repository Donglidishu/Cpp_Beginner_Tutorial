#pragma once
#include "speaker.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 设计演讲管理类
class SpeechManager
{
  public:
    // 构造函数
    SpeechManager();

    // 菜单功能
    void showMenu();

    // 退出
    void exitSystem();

    // 初始化容器和属性
    void initSpeech();
    // 保存第一轮比赛选手编号容器
    vector<int> v1;
    // 第一轮晋级选手编号容器
    vector<int> v2;
    // 前三名选手编号容器
    vector<int> vVictory;
    // 存放编号以及对应选手容器
    map<int, Speaker> m_Speaker;
    // 存放比赛轮数
    int m_Index;

    // 创建选手
    void createSpeaker();

    // 开始比赛 整个比赛流程控制函数
    void startSpeech();

    // 抽签函数
    void speechDraw();

    // 比赛
    void speechContest();

    // 显示得分
    void showScore();

    // 清屏操作
    void screenClear();

    // 保存记录
    void saveRecord();

    // 读取记录
    void loadRecord();

    // 判断文件是否为空
    bool fileIsEmpty;

    // 存放往届记录的容器
    map<int, vector<string>> m_Record;

    // 析构函数
    ~SpeechManager();
};