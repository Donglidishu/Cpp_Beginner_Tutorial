#include <iostream>
#include <string>
using namespace std;
// 定义学生结构体
struct Student
{
    string name;
    int age;
    int score;
};

// 打印学生参数信息
// 1.值传递
void PrintStudent(Student s)
{
    // s.age = 100; 则输出结果中：子函数输出的年龄为100，main函数输出的年龄仍为18，因为值传递不改变实参
    cout << "子函数中 姓名:" << s.name << " 年龄为:" << s.age << " 分数为:" << s.score << endl;
}

// 2.地址传递
void PrintStudent2(Student *p)
{
    // p->age = 200; 则输出结果中：子函数2和main函数输出的年龄均为200，因为地址传递可以间接更改实参
    cout << "子函数2中 姓名:" << p->name << " 年龄为:" << p->age << " 分数为:" << p->score << endl;
}

int main()
{
    // 结构体做函数参数
    // 将学生传入到一个函数中，打印学生身上的所有信息
    Student s;
    s.name = "hyt";
    s.age = 18;
    s.score = 750;

    cout << "main函数中 姓名:" << s.name << " 年龄为:" << s.age << " 分数为:" << s.score << endl;

    PrintStudent(s);
    PrintStudent2(&s);

    return 0;
}
// 小结：如果在结构体做参数函数时不想修改主函数中的数据，则用值传递，反之使用地址传递