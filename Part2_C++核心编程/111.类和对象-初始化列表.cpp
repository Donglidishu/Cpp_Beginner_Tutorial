#include <iostream>
using namespace std;
// 初始化列表
class Person
{
  public:
    // 传统初始化操作
    //  Person(int a,int b, int c)
    //  {
    //      m_A = a;
    //      m_B = b;
    //      m_C = c;
    //  }

    // 初始化列表初始化属性
    // 构造函数(参数列表):参数1(值1), 参数2(值2)....{}
    Person(int a, int b, int c)
        : m_A(a), m_B(b), m_C(c)
    {
    }

    int m_A;
    int m_B;
    int m_C;
};

void test01()
{
    Person p(30, 20, 10);
    cout << "a = " << p.m_A << endl;
    cout << "b = " << p.m_B << endl;
    cout << "c = " << p.m_C << endl;
}
int main()
{
    test01();
    return 0;
}