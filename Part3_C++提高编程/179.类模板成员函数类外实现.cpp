#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
  public:
    Person(T1 name, T2 age);
    // {
    //     this->m_Name = name;
    //     this->m_Age = age;
    // }

    void showPerson();
    // {
    //     cout << "姓名: " << this->m_Name << endl;
    //     cout << "年龄: " << this->m_Age << endl;
    // }
    T1 m_Name;
    T2 m_Age;
};

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) // 要写模板参数列表
{
    this->m_Name = name;
    this->m_Age = age;
}

// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名: " << this->m_Name << endl;
    cout << "年龄: " << this->m_Age << endl;
}

int main()
{
    Person<string, int> p1("zhangsan", 18);
    p1.showPerson();
    return 0;
}