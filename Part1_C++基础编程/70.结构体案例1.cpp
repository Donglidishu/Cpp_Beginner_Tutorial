#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string sName;
    int score;
};

struct Teacher
{
    string tName;
    // 学生数组
    Student sArry[5];
};

void allocateSpace(Teacher tArray[], int len)
{
    for (int i = 0; i < 3; i++)
    {
        string nameSeed = "ABCDE";
        // 给老师信息赋值
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];

        // 给老师所带的学生信息赋值
        for (int j = 0; j < 5; j++)
        {
            // 给名称赋值
            tArray[i].sArry[j].sName = "Student_";
            tArray[i].sArry[j].sName += nameSeed[j];

            // 给分数赋值
            int random = rand() % 101; // 生成0-100的随机数
            tArray[i].sArry[j].score = random;
        }
    }
}

void printInfo(Teacher tArray[3], int len)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "老师的名字为:" << tArray[i].tName << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生" << tArray[i].sArry[j].sName << "的分数为:" << tArray[i].sArry[j].score << endl;
        }
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1.创建3名老师数组
    Teacher tArray[3];

    // 2.通过函数给3名老师的信息赋值，并给老师带的学生的信息赋值
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);

    // 3.打印所有老师及其学生的信息
    printInfo(tArray, len);

    return 0;
}
