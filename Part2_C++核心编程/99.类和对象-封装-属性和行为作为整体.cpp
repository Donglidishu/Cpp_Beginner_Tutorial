#include <iostream>
using namespace std;

// 设计一个圆类，求圆的周长
const double PI = 3.14;
// class代表设计一个类，后面紧跟名称
class Circle
{
    // 访问权限
    // 公共权限
  public:
    // 属性
    // 半径
    int m_r;

    // 行为
    // 获取圆的周长
    // 函数
    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};

int main()
{
    // 通过圆类创建具体圆（对象）
    // 实例化：通过一个类创建一个对象的过程
    Circle c1;
    // 给圆对象的属性赋值
    c1.m_r = 10;
    cout << "c1的周长为: " << c1.calculateZC() << endl;
    return 0;
}