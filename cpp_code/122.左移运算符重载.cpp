#include <iostream>
#include <ostream>
using namespace std;

// 左移运算符重载

class Person
{
    friend ostream &operator<<(ostream &cout, Person &p);
    friend void test01();

  private:
    // 利用成员函数重载 左移运算符 p.operator<<(cout) 简化版本 p << cout 不符合预期
    // 通常不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    //  void operator<<(cout)
    //  {

    // }

    int m_A;
    int m_B;
};

// 只能利用全局函数重载左移运算符
ostream &operator<<(ostream &cout, Person &p) // 本质 operator<< (cout ,p)   简化 cout << p
{
    cout << "m_A = " << p.m_A << " m_B = " << p.m_B << endl;
    return cout; // 为了链式编程，如果不写则37行的p之后的<<会报错
}

void test01()
{
    Person p;
    p.m_A = 10;
    p.m_B = 10;

    cout << p << endl;
}

int main()
{
    test01();
    return 0;
}