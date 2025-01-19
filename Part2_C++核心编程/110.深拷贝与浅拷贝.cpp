#include <cstddef>
#include <iostream>
using namespace std;
// 浅拷贝：简单的复制拷贝操作
// 深拷贝：在堆上重新申请空间进行拷贝

// 如果使用编译器提供的默认的拷贝构造函数，只会进行浅拷贝，p的m_Height的地址会被值拷贝给p2，那么两个成员的m_Height均指向同一块内存
// 而p和p2的析构函数依次执行时，p2.m_Height指向的内存已经被释放，重复释放导致程序崩溃
// 因此自己写拷贝构造来解决浅拷贝带来的问题

class Person
{
  public:
    Person()
    {
        cout << "默认构造函数调用" << endl;
    }
    Person(int a, int height)
    {
        cout << "有参构造函数调用" << endl;
        m_Age = a;
        m_Height = new int(height);
    }

    // 自己实现拷贝构造解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height;编译器默认提供的拷贝，也是报错的原因
        // 深拷贝操作
        m_Height = new int(*p.m_Height);
    }

    ~Person()
    {
        // 析构，将堆区开辟的数据进行释放
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL; // 防止指针置空
        }
        cout << "析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height;
};

void test01()
{
    Person p(18, 160);
    cout << "p age = " << p.m_Age << "height = " << *p.m_Height << endl;

    Person p2(p);
    cout << "p2 age = " << p.m_Age << "height = " << *p2.m_Height << endl;
}

int main()
{
    test01();
    return 0;
}