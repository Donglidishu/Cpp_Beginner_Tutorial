#include <iostream>
#include <string>
using namespace std;

class Building;

class goodGuy
{
  public:
    goodGuy();

    void visit();  // 让visit函数可以访问Building中私有成员
    void visit2(); // 让visit2函数不可以访问Building中私有成员

    Building *building;
};

class Building
{
    friend void goodGuy::visit(); // 告诉编译器goodGuy类下的visit函数可以访问本类的私有成员

  public:
    Building();

    string m_SittingRoom;

  private:
    string m_BedRoom;
};

// 类外实现
Building::Building()
{
    m_SittingRoom = "sittingRoom";
    m_BedRoom = "bedRoom";
}

goodGuy::goodGuy()
{
    building = new Building;
}

void goodGuy::visit()
{
    cout << "visit is visiting: " << building->m_BedRoom << endl;
}

void goodGuy::visit2()
{
    cout << "visit2 is visiting: " << building->m_SittingRoom << endl;
}

void test01()
{
    goodGuy gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();
    return 0;
}