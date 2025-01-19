#include <iostream>
using namespace std;

// 多继承语法
// 开发中不建议使用多继承

class Base1
{
  public:
    Base1()
    {
        m_A = 100;
    }

    void func1()
    {
        cout << "Base1 - func1()调用" << endl;
    }

    int m_A;
};

class Base2
{
  public:
    Base2()
    {
        m_B = 200;
    }

    void func2()
    {
        cout << "Base2 - func2()调用" << endl;
    }

    int m_B;
};

// 子类 需要继承Base1 和 Base2
// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2
class Son : public Base1, public Base2
{
  public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }

    void func3()
    {
        cout << "Son - func3()调用" << endl;
    }

    int m_C;
    int m_D;
};

void test01()
{
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl;
    // 当子类中出现和父类同名成员，需要加作用域区分调用
    cout << "Base1 中的 m_A = " << s.Base1::m_A << endl;
    cout << "Base2 中的 m_B = " << s.Base2::m_B << endl;
}
int main()
{
    test01();
    return 0;
}