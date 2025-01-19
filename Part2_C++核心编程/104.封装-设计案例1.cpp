#include <iostream>
using namespace std;
// 立方体类设计
// 1.创建立方体类
// 2.设计属性
// 3.设计行为获取立方体面积和体积
// 4.分别利用全局函数和成员函数判断两个立方体是否相等
class Cube
{
  public:
    // 修改长
    void setL(int L)
    {
        m_L = L;
    }
    // 获取长
    int getL()
    {
        return m_L;
    }

    // 修改宽
    void setW(int W)
    {
        m_W = W;
    }
    // 获取宽
    int getW()
    {
        return m_W;
    }

    // 修改高
    void setH(int H)
    {
        m_H = H;
    }
    // 获取高
    int getH()
    {
        return m_H;
    }

    // 计算并获取表面积
    int caculateS()
    {
        return (m_H * m_L + m_H * m_W + m_L * m_W) * 2;
    }

    // 计算并获取体积
    int caulateV()
    {
        return m_H * m_L * m_W;
    }

  private:
    int m_L;
    int m_H;
    int m_W;
};

int main()
{
    Cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);

    cout << "表面积为" << c1.caculateS() << endl;
    cout << "体积为" << c1.caulateV() << endl;

    cout << "表面积为(单独计算)" << (c1.getH() * c1.getW() + c1.getH() * c1.getL() + c1.getL() * c1.getW()) * 2 << endl;
    cout << "体积为(单独计算)" << c1.getH() * c1.getL() * c1.getW() << endl;

    return 0;
}