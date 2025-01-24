#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
  public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

  public:
    string m_Name;
    int m_Age;
};

void test01()
{
    vector<Person> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "姓名: " << (*it).m_Name << " 年龄: " << (*it).m_Age << endl; //*it加括号，运算优先级问题，. (对象访问运算符)的运算优先级高于 *
        cout << "姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl; // 或者使用->直接通过指针访问
    }
}

// 存放自定义数据类型 指针
void test02()
{
    vector<Person *> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名: " << (*it)->m_Name << " 年龄: " << (*it)->m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}