#include "Circle.h"

// 设置和获取半径
void Circle::setR(int r)
{
    m_R = r;
}
int Circle::getR()
{
    return m_R;
}

// 设置和获取圆心
void Circle::setC(Point center)
{
    m_Center = center;
}
Point Circle::getC()
{
    return m_Center;
}
