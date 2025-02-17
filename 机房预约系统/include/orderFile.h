#pragma once
#include "string"
#include <map>
using namespace std;

class OrderFile
{
  public:
    OrderFile();

    // 更新预约记录
    void updateOrder();

    // 记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
    // 第二个map中 key --- 属性(日期，时间段等) value --- 属性对应的值
    map<int, map<string, string>> m_orderDate;

    // 预约记录条数
    int m_Size;
};