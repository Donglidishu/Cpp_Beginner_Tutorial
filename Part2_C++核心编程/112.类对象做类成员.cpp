#include <iostream>
#include <string>
using namespace std;
// 类对象作为类成员

class Phone
{
  public:
    Phone(string pName)
    {
        m_PName = pName;
        cout << "Phone构造函数调用" << endl;
    }

    // 手机品牌名称
    string m_PName;

    ~Phone()
    {
        cout << "Phone的析构函数调用" << endl;
    }
};
class Person
{
  public:
    // Phone m_Phone = pName;隐式转换法
    Person(string name, string pName)
        : m_Name(name), m_Phone(pName)
    {
        cout << "Person的构造函数调用" << endl;
    }
    // 姓名
    string m_Name;
    // 手机
    Phone m_Phone;

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};
// 当其他类对象作为本类成员，先构造类对象再构造自身
// 析构顺序与构造相反

void test01()
{
    Person p("zhangsan", "xiaomi14");

    cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
}

int main()
{
    test01();
    return 0;
}