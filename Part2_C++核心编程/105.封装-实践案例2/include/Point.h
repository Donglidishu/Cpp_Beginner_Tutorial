#pragma once
#include <iostream>
using namespace std;

class Point
{
  public:
    // 设置和获取x坐标
    void setX(int x);
    int getX();
    
    // 设置和获取y坐标
    void setY(int y);
    int getY();

  private:
    int m_X;
    int m_Y;
};