#include <iostream>
#include <string>
using namespace std;

// 结构体嵌套结构体

// 定义学生结构体
struct Student
{
    string name;
    int age;
    int score;
};

// 定义教师结构体
struct Teacher
{
    int id;      // 教师编号
    string name; // 教师姓名
    int age;     // 教师年龄
    Student stu; // 辅导的学生
};

int main()
{
    // 创建老师
    Teacher t;
    t.id = 7174;
    t.name = "hyt";
    t.age = 18;
    t.stu.name = "xzk";
    t.stu.age = 18;
    t.stu.score = 593;

    cout << "老师编号:" << t.id << " 老师姓名:" << t.name << " 老师年龄:" << t.age << endl;
    cout << "老师辅导的学生姓名:" << t.stu.name << " 学生年龄:" << t.stu.age << " 学生分数:" << t.stu.score << endl;

    // 总结：结构体中可以定义另一个结构体作为成员，用来解决实际问题

    return 0;
}