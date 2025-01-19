#include <iostream>
#include <string>
using namespace std;
// 成员属性设为私有
//  1.可以自己控制读写权限
//  2.对于写可以检测数据有效性

class Person
{
  public:
    void setName(string name) // 修改姓名函数
    {
        m_Name = name;
    }

    void setIdol(string idol)
    {
        m_Idol = idol;
    }

    string getName() // 实现读取姓名
    {
        return m_Name;
    }

    int getAge() // 实现读取年龄
    {
        return m_Age;
    }

    // 设置年龄(0~150)
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "年龄 " << age << " 输入有误，修改失败" << endl;
            return;
        }
        m_Age = age;
        cout << "修改成功" << endl;
    }

  private:
    string m_Name;  // 姓名 可读可写
    int m_Age = 18; // 年龄 只读 也可以写(年龄必须在 0 到 150 之间)
    string m_Idol;  // 只写
};

int main()
{
    Person p1;
    // p1.m_Name = "张三"; //由于权限无法直接访问

    // 修改年龄(0~150)
    p1.setAge(60);

    // 姓名可读可写
    p1.setName("张三");
    cout << "姓名: " << p1.getName() << endl;

    // 获取年龄(只读)
    cout << "年龄: " << p1.getAge() << endl;

    // idol(只写)
    p1.setIdol("YOASOBI");

    return 0;
}