#include <iostream>
#include <string>
using namespace std;

// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型

// 1.创建学生数据类型，学生包括(姓名，年龄，分数)
// 自定义数据类型，一些数据类型集合组成一个数据类型
// 语法: struct 类型名称 { 成员列表 }
struct Student // 创建结构体的时候struct不能省略，但后续创建变量的时候可以省略
{
    // 成员列表

    // 姓名
    string name;
    // 年龄
    int age;
    // 分数
    int score;
};

int main()
{
    // 2.通过学生类型创建具体学生

    // 2.1 struct Student s1
    struct Student s1; // 可以不写struct，就像创建int一样
    // 给s1赋值，可以通过.访问结构体变量中的属性
    s1.name = "xzk";
    s1.age = 18;
    s1.score = 593;

    cout << s1.name << "的年龄是" << s1.age << ", 总分为" << s1.score << endl;

    // 2.2 struct Student s2 = { 属性(按定义顺序) }
    struct Student s2 = {"hyt", 18, 750};
    cout << s2.name << "的年龄是" << s2.age << ", 总分为" << s2.score << endl;

    // 2.3 定义结构体时顺便定义(不推荐)
    /*


        struct Student
        {
            string name;
            int age;
            int score;
        }s3;

        //下面代码在main函数中
        s3.name = "...";
        s3.age = ...;
        s3.score = ...;


    */

    return 0;
}
