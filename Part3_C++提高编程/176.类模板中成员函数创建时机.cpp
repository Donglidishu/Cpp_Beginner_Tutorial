#include <iostream>
using namespace std;

// 类模板中成员函数创建时机
// 类模板中成员函数在调用时才会创建

class Person1
{
  public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
  public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template <class T>
class MyClass
{
  public:
    T obj;

    // 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成

    void fun1()
    {
        obj.showPerson1();
    }
    void fun2()
    {
        obj.showPerson2();
    }
};

void test01()
{
    MyClass<Person1> m;
    m.fun1(); // 模板调用之前无法确定obj的类型，而调用模板时会以Person1传入模板，实例化出类型为Person1的对象，此时因为func2()并不是Person1的成员函数，因此会报错
    // m.fun2();
}

int main()
{
    test01();
    return 0;
}