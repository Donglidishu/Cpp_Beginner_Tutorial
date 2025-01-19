#include <iostream>
using namespace std;
// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person
{
  public:
    static void func()
    {
        cout << "static void func调用" << endl;
        m_A = 100;
        // m_B = 200;静态成员函数只能访问静态成员变量
        // 静态成员函数是属于类本身的，而不是属于类的某个特定对象
        // 静态成员函数可以在没有类的对象实例的情况下被调用
    }

  private:
    static void func2()
    {
        cout << "static void func2调用" << endl;
    }

    static int m_A;
    int m_B;
};

int Person::m_A = 0;
void test01()
{
    // 1.通过对象进行访问
    Person p;
    p.func();

    // 2.通过类名访问
    Person::func();
    // Person::func2(); 权限为私有，类外无法访问
}

int main()
{
    test01();
    return 0;
}