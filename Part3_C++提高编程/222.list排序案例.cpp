#include <iostream>
#include <list>
using namespace std;

// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

class Person
{
  public:
    Person(string name, int age, int height)
        : m_Name(name), m_Age(age), m_Height(height)
    {
    }

  public:
    string m_Name;
    int m_Age;
    int m_Height;
};

bool compare(Person p1, Person p2)
{
    if (p1.m_Age == p2.m_Age)
    {
        return p1.m_Height > p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age;
    }
}

int main()
{
    list<Person> personList;
    // 这种情况使用emplace_back更加高效，因为emplace_back直接在容器内构造对象，避免了使用push_back时先创建临时对象再拷贝的操作
    personList.emplace_back("刘备", 35, 175);
    personList.emplace_back("曹操", 45, 180);
    personList.emplace_back("孙权", 40, 170);
    personList.emplace_back("赵云", 25, 190);
    personList.emplace_back("张飞", 35, 160);
    personList.emplace_back("关羽", 35, 200);
    cout << "排序前: " << endl;

    for (list<Person>::iterator it = personList.begin(); it != personList.end(); it++)
    {
        cout << "姓名: " << (*it).m_Name << " 年龄: " << (*it).m_Age << " 身高: " << (*it).m_Height << endl;
    }

    personList.sort(compare);

    cout << "-----------------------------------" << endl;
    cout << "排序后: " << endl;

    for (list<Person>::iterator it = personList.begin(); it != personList.end(); it++)
    {
        cout << "姓名: " << (*it).m_Name << " 年龄: " << (*it).m_Age << " 身高: " << (*it).m_Height << endl;
    }

    return 0;
}