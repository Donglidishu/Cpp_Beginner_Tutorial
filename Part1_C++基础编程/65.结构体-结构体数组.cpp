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
    Student stuArray[2] = // 可省略struct关键字
        {

            {"hyt", 18, 750},
            {"xzk", 18, 593}

        };

    for (int i = 0; i < 2; i++)
    {
        cout << "姓名：" << stuArray[i].name << " 年龄：" << stuArray[i].age << " 分数：" << stuArray[i].score << endl;
    }

    return 0;
}