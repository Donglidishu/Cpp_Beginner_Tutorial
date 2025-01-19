#include <iostream>
#include <string>
using namespace std;
// 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

class Student
{
    // 类中的属性和行为统称为成员
    // 属性  成员属性/成员变量
    // 行为  成员函数/成员方法

  public: // 公共权限
    // 属性
    string m_name; // 姓名
    int m_id;      // 学号

    // 行为
    void showStudent()
    {
        cout << "姓名: " << m_name << " 学号: " << m_id << endl;
    }

    // 可以通过行为创建学生信息（方法二）
    void setName(string name)
    {
        m_name = name;
    }
    void setId(int id)
    {
        m_id = id;
    }
};

int main()
{
    // 创建学生
    Student s1;
    Student s2;

    // 给s1对象的属性赋值
    // 方法一
    s1.m_name = "张三";
    s1.m_id = 114;

    // 方法二
    s2.setName("李四");
    s2.setId(115);

    // 分别展示对象s1和s2的信息
    s1.showStudent();
    s2.showStudent();

    return 0;
}