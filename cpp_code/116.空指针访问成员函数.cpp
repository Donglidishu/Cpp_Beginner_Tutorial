#include <cstddef>
#include <iostream>
#pragma clang diagnostic ignored "-Wtautological-undefined-compare" // 忽略警告
using namespace std;

// 空指针访问成员函数

// 此部分内容不符合c++规范，仅供参考
// ChatGpt: 通过空指针调用非静态成员函数是 未定义行为，尽管在某些场景下代码可能 “看起来” 能运行，但它违反了 C++ 标准的假设
// 可能导致程序崩溃或运行时错误。正确的方式是确保对象的指针有效，或改用静态成员函数。

class Person
{
  public:
    void showClassName()
    {
        cout << "this is a Person classs" << endl;
    }

    void showPersonAge()
    {
        if (this == NULL)
        {
            return;
        }
        cout << "m_Age" << m_Age << endl; // 属性前面会默认有this指针，此时this指针为空指针，自然会报错
    }
    int m_Age;
};

void test01()
{
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}

int main()
{
    test01();
    return 0;
}