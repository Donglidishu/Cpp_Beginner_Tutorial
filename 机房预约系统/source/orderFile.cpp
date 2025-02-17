#include "orderFile.h"
#include "globalFile.h"
#include <fstream>
#include <utility>

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
        this->m_orderDate.insert(make_pair(this->m_Size, tempMap));
        this->m_Size++;
    }
    ifs.close();
}