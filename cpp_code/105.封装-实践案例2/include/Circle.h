#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Circle
{
  public:
    // 设置和获取半径
    void setR(int r);
    int getR();

    // 设置和获取圆心
    void setC(Point center);
    Point getC();

  private:
    int m_R;        // 半径
    Point m_Center; // 圆心
};