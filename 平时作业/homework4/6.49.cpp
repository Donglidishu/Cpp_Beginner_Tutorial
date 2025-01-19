#include <iostream>
using namespace std;

inline double circleArea(double radius)
{
    return 3.14159 * radius * radius;
}

int main()
{
    double radius;

    cout << "请输入圆的半径: ";
    cin >> radius;

    double area = circleArea(radius);
    cout << "半径为 " << radius << " 的圆的面积是: " << area << endl;

    return 0;
}