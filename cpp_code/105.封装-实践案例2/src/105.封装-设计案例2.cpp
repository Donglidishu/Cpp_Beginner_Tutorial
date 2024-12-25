#include <cmath>
#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;


// 判断点和圆的关系
void isInCircle(Circle &c, Point &p)
{
    // 计算到圆心距离
    int distence = pow(c.getC().getX() - p.getX(), 2) + pow(c.getC().getY() - p.getX(), 2);
    if (distence == pow(c.getR(), 2))
    {
        cout << "点在圆上" << endl;
    }
    else if (distence < pow(c.getR(), 2))
    {
        cout << "点在圆内" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }
}

int main()
{
    Circle c1;
    Point p1;
    Point center;
    center.setX(0);
    center.setY(0);

    p1.setX(5);
    p1.setY(5);

    c1.setC(center);
    c1.setR(10);

    isInCircle(c1, p1);

    return 0;
}