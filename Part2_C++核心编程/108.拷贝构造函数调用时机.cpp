#include <iostream>
using namespace std;

class Person
{
  public:
    Person()
    {
        cout << "Person默认构造函数调用" << endl;
    }
    Person(int age)
    {
        cout << "Person有参构造函数调用" << endl;
        m_age = age;
    }
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用" << endl;
        m_age = p.m_age;
    }

    // 析构函数
    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
    int m_age;
};

// 拷贝构造函数调用时机

// 1.使用一个已经创建完毕的对象来初始化一个对象
void test01()
{
    Person p1(10);
    Person p2(p1);
    cout << "p2的年龄为: " << p2.m_age << endl;
}

// 2.值传递的方式给函数参数传值
void doWork(Person p) // 值传递 调用拷贝构造函数 这也就解释了为什么值传递不改变实参
{
}

void test02()
{
    Person p;
    doWork(p);
}

// 3.值方式返回局部对象
Person doWork02()
{
    Person p1;
    return p1;
}
void test03()
{
    Person p = doWork02();
}
// 此处理论上会调用拷贝构造函数，但编译器对返回值进行优化(RVO 是一种编译器优化技术。编译器会在可能的情况下直接构造返回值到调用者的目标内存位置，而不是构造一个临时对象再拷贝它。)
// 因此输出中并没有拷贝构造函数的输出

int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}