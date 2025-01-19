#include <iostream>
using namespace std;
// 构造函数调用规则
// 1.创建一个类，c++编译器会给每个类添加至少3个函数
// 默认构造(空实现)
// 析构函数(空实现)
// 拷贝构造(值拷贝)

// 2.如果写了有参构造，编译器就不再提供默认构造，但仍提供拷贝构造(也就是说如果写有参构造，默认构造也必须要自己写)
// 写拷贝则编译器不提供拷贝

// 逻辑：拷贝 > 有参 > 默认，自己写大的那下面的小的也得自己写

class Person
{
  public:
    Person()
    {
        cout << "Person默认构造函数调用" << endl;
    }

    Person(int a)
    {
        cout << "Person有参构造函数调用" << endl;
        m_Age = a;
    }

    // 不写拷贝构造，编译器也会默认进行值拷贝
    //  Person(const Person &p)
    //  {
    //      cout << "Person拷贝构造函数调用" << endl;
    //      m_Age = p.m_Age;
    //  }

    ~Person()
    {
        cout << "Person析构构造函数调用" << endl;
    }

    int m_Age;
};

void test01()
{
    Person p;
    p.m_Age = 18;

    Person p2(p);
    cout << "p2 age = " << p2.m_Age << endl;
}

void test02()
{
    Person p(28);

    Person p2(p);
    cout << "p2 age = " << p2.m_Age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}