#include "orderFile.h"
#include "globalFile.h"
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;    // 日期
    string time;    // 时间段
    string stuId;   // 学生编号
    string stuName; // 学生姓名
    string roomId;  // 机房编号
    string status;  // 预约状态

    this->m_Size = 0;

    while (ifs >> date && ifs >> time && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        // // 测试代码
        // cout << date << endl;
        // cout << time << endl;
        // cout << stuId << endl;
        // cout << stuName << endl;
        // cout << roomId << endl;
        // cout << status << endl;

        string key;
        string value;
        map<string, string> tempMap;

        int pos = date.find(":");
        if (pos != -1)
        {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }

        pos = time.find(":");
        if (pos != -1)
        {
            key = time.substr(0, pos);
            value = time.substr(pos + 1, time.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }

        pos = time.find(":");
        if (pos != -1)
        {
            key = time.substr(0, pos);
            value = time.substr(pos + 1, time.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }

        pos = stuId.find(":");
        if (pos != -1)
        {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }

        pos = stuName.find(":");
        if (pos != -1)
        {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }

        pos = roomId.find(":");
        if (pos != -1)
        {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }

        pos = status.find(":");
        if (pos != -1)
        {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            tempMap.insert(make_pair(key, value));
        }
        this->m_orderData.insert(make_pair(this->m_Size, tempMap));
        this->m_Size++;
    }

    // // 测试代码
    // for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
    // {
    //     cout << "key = " << it->first << " value = " << endl;
    //     for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
    //     {
    //         cout << mit->first << " " << mit->second << " ";
    //     }
    //     cout << endl;
    // }

    ifs.close();
}

void OrderFile::updateOrder()
{
    if (this->m_Size == 0)
    {
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < this->m_Size; i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
    ofs.close();
}