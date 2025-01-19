#include <iostream>
using namespace std;

class Building;
class goodGuy
{
  public:
    goodGuy();
    void visit(); // 参观函数 访问Building中的属性

    Building *building;
};

class Building
{
    friend class goodGuy; // 将goodGuy类设置成Building的友元
  public:
    Building();

  public:
    string m_SittingRoom;

  private:
    string m_BedRoom;
};

// 类外写成员函数
Building::Building()
{
    m_SittingRoom = "sittingRoom";
    m_BedRoom = "bedRoom";
}

goodGuy::goodGuy()
{
    // 创建一个建筑物对象
    building = new Building;
}

void goodGuy::visit()
{
    cout << "goodGuy is visiting: " << building->m_SittingRoom << endl;
    cout << "goodGuy is visiting: " << building->m_BedRoom << endl;
}

void test01()
{
    goodGuy gg;
    gg.visit();
}

int main()
{

    return 0;
}