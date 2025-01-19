#include <iostream>
using namespace std;

class Person
{
  public:
    Person(int age)
    {
        // this指针指向被调用的成员函数所属的对象**
        this->age = age;
    }

    Person &PersonAddAge(Person &p) // 返回引用来支持test02中的链式调用
    {
        this->age += p.age;

        // this是指向p2的指针，而*this指向的就是p2这个本体
        return *this;
    }
    int age;
};

// 1.解决名称冲突
void test01()
{
    Person p(18);
    cout << "p的年龄" << p.age << endl;
}

// 2.返回对象本身用*this
void test02()
{
    Person p1(10);
    Person p2(20);

    // 链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "p2 age: " << p2.age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}