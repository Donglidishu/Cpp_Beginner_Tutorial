#include <iostream>
using namespace std;

// 继承中同名成员处理

class Base
{
  public:
    Base()
    {
        m_A = 100;
    }

    static void func()
    {
        cout << "Base - static - func()调用" << endl;
    }

    static void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }
    static int m_A;
};
int Base::m_A = 100;

class Son : public Base
{
  public:
    Son()
    {
        m_A = 200;
    }

    static void func()
    {
        cout << "Son - static - func()调用" << endl;
    }

    static int m_A;
};
int Son::m_A = 200;

// 同名静态属性
void test01()
{
    // 1.通过对象访问
    Son s;
    cout << "通过对象访问" << endl;
    cout << "Son 中的 m_A = " << s.m_A << endl;
    cout << "Base 中的 m_A = " << s.Base::m_A << endl;

    // 2.通过类名访问
    cout << "通过类名访问" << endl;
    cout << "Son 中的 m_A = " << Son::m_A << endl;
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下的m_A
    cout << "Base 中的 m_A = " << Son::Base::m_A << endl;
}

// 同名成员函数
void test02()
{
    // 1.通过对象访问
    cout << "通过对象访问" << endl;
    Son s;
    s.func(); // 直接调用是调用子类中的func
    s.Base::func();

    // 2.通过类名访问
    cout << "通过类名访问" << endl;
    Son::func();
    Son::Base::func();

    // 子类中出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
    // 如果想访问父类中被隐藏的同名成员，需要加作用域
    Son::Base::func(100);
}

int main()
{
    // test01();
    test02();
    return 0;
}