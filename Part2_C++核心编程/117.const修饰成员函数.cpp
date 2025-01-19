#include <iostream>
using namespace std;

// 常函数
class Person
{
  public:
    Person()
    {
        cout << "消除警报用" << endl;
        m_A = 100; // 为了防止Line 43报错，因为常对象一创建就要初始化，但m_A未赋初值所以导致默认构造会报错
    }

    // this指针的本质是指针常量 指针的指向是不可修改的

    // const Person * const this;
    // 第一个const指的是this指向的值是常量 不可修改
    // 第二个const指的是this的指向不可修改

    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const
    {
        // m_A = 100;
        // this = NULL; //this指针不可以修改指针的指向
        this->m_B = 100; // 有mutable
    }

    void func()
    {
    }

    int m_A;
    mutable int m_B; // 特殊变量，即使在常函数中也可以修改这个值
};

void test01()
{
    Person p;
    p.showPerson();
}

void test02()
{
    const Person p2;
    // p2.m_A = 100;
    p2.m_B = 100; // m_B有mutable，在常对象下也可以修改

    // 常对象只能调用常函数
    p2.showPerson();
    // p2.func();常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main()
{

    return 0;
}

// 一开始写到35行p2会报错Default initialization of an object of const type 'const Person' without a user-provided default constructor (fix available)clang(default_init_const)
// 这是因为在Person类中m_A没有初始化，如果执行默认构造编译器就会报错