#include <iostream>
#include <string>
using namespace std;

class Building
{

    friend void goodGuy(Building *building);

  public:
    Building()
    {
        m_SittingRoom = "sittingroom";
        m_BedRoom = "bedroom";
    }

    string m_SittingRoom; // 客厅

  private:
    string m_BedRoom; // 卧室
};

// 全局函数
void goodGuy(Building *building)
{
    cout << "goodGuy global function is visiting: " << building->m_SittingRoom << endl;
    cout << "goodGuy global function is visiting: " << building->m_BedRoom << endl;
}

void test01()
{
    Building building;
    goodGuy(&building);
}
int main()
{
    test01();
    return 0;
}