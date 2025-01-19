#include <iostream>
using namespace std;

// 成员变量和成员函数分开存储
class Person
{
  public:
    int m_A;        // 非静态成员变量 属于类的对象上的
    static int m_B; // 静态成员变量 不属于类的对象上
    void func()     // 非静态成员函数 不属于类的对象上
    {
    }
    static void func2() // 静态成员函数 不属于类的对象上
    {
    }
};

int Person::m_B = 1;

void test01()
{
    Person p;
    // 空对象占用内存空间为1
    // c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有独一无二的内存地址
    cout << "sizeof(p) = " << sizeof(p) << endl;
}

void test02()
{
    Person p;
    cout << "sizeof(p) = " << sizeof(p) << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}