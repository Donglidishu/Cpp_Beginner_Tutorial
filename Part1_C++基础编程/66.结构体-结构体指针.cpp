#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    // 创建结构体变量
    Student s = {"hyt", 18, 750};

    // 创建结构体指针
    Student *p = &s;

    //可以用 -> 访问结构体指针中的结构体属性
    cout << "姓名:" << p->name << " 年龄:" << p->age << " 分数:" << p->score << endl;

    return 0;
}