#include <iostream>
using namespace std;

// 静态成员变量

class Person
{
  public:
    // 所有对象共享同一份数据
    // 编译阶段分配内存
    // 类内声明 类外初始化对象
    static int m_A;

    // 静态成员变量也有访问权限
  private:
    static int m_B;
};
int Person::m_A = 100;
int Person::m_B = 200; // private权限只影响类外访问，不影响一开始的初始化。静态成员变量必须要在类外进行初始化

void test01()
{
    Person p;
    cout << p.m_A << endl;

    Person p2;
    p2.m_A = 200;

    // 100? 200√
    cout << p2.m_A << endl;
}

void test02()
{
    // 静态成员变量不属于某个对象上 所有对象共享同一份数据
    // 因此静态成员变量有两种访问方式
    // 1.通过对象进行访问
    Person p;
    cout << p.m_A << endl;
    // 2.通过类名进行访问
    cout << Person::m_A << endl;

    // cout << Person::m_B << endl; 类外访问不到私有静态成员变量
}
int main()
{
    // test01();
    test02();
    return 0;
}