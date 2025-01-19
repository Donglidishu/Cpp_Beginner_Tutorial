#include <iostream>
using namespace std;

// 赋值运算符重载

class Person
{
  public:
    Person(int age)
    {
        m_Age = new int(age);
    }

    int *m_Age;

    ~Person()
    {
        if (m_Age != nullptr)
        {
            delete m_Age;
            m_Age = nullptr;
        }
    }

    // 重载 赋值运算符
    Person &operator=(Person &p)
    {
        // 编译器提供的是浅拷贝
        // m_Age = p.m_Age

        // 应该先判断是否有属性在堆区 如果有先释放干净 然后再深拷贝
        if (m_Age != nullptr)
        {
            delete m_Age;
            m_Age = nullptr;
        }

        // 深拷贝
        m_Age = new int(*p.m_Age);
        return *this;
    }
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p2 = p1; // 赋值操作
    // 报错原因：浅拷贝 堆区内存重复释放
    // 解决方式：深拷贝
    // 重载赋值运算符

    p3 = p2 = p1; // 赋值操作

    cout << "p1 age: " << *p1.m_Age << endl;
    cout << "p2 age: " << *p2.m_Age << endl;
    cout << "p3 age: " << *p3.m_Age << endl;
}

int main()
{
    test01();
    return 0;
}