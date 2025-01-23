#include <iostream>
#include <string>
using namespace std;

// 先让编译器知道有Person类和showPerson成员函数
template <class T1, class T2>
class Person;

template <class T1, class T2>
void showPerson(Person<T1, T2> &p)
{
    cout << "类外实现" << p.m_Name << " " << p.m_Age << endl;
}

// 通过全局函数打印Person信息
template <class T1, class T2>
class Person
{
    // 全局函数类内实现 加个friend关键字
    //  friend void showPerson(Person<T1, T2> p)
    //  {
    //      cout << "类内实现" << p.m_Age << " " << p.m_Name << endl;
    //  }

    // 全局函数类外实现
    friend void showPerson<>(Person<T1, T2> &p); // 在作为友元时需要尖括号显示指定该函数为模版函数，否则会默认为普通函数导致编译错误
                                                 // 类内实现的不需要加，因为编译器知道该函数是与类模板相关的

  public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

  private:
    T1 m_Name;
    T2 m_Age;
};

void test01()
{
    Person<string, int> p2("张三", 18);
    showPerson(p2);
}

int main()
{
    test01();
    return 0;
}