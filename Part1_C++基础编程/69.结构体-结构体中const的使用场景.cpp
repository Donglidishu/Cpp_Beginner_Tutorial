#include <iostream>
#include <string>
using namespace std;

// const的使用场景
struct Student
{
    string name;
    int age;
    int score;
};

// 如果使用值传递，会复制出来很多新的数据，导致内存浪费
// 将函数中的形参改为指针可以节省内存空间，而且不会复制新的副本出来

void PrintStudent(const Student *s) // 可以看成是只读
{
    // s->age = 100; //加入const之后一旦有修改的操作就会报错，防止误操作
    cout << "姓名:" << s->name << " 年龄:" << s->age << " 分数:" << s->score << endl;
}

int main()
{
    // 创建结构体变量
    Student s = {"hyt", 18, 750};

    // 通过函数打印结构体变量的信息
    PrintStudent(&s);

    cout << "main函数中年龄为:" << s.age << endl;

    return 0;
}
