#include <iostream>
using namespace std;

int qualityPoints(int averageScore)
{
    if (averageScore >= 90 && averageScore <= 100)
    {
        return 4;
    }
    else if (averageScore >= 80 && averageScore <= 89)
    {
        return 3;
    }
    else if (averageScore >= 70 && averageScore <= 79)
    {
        return 2;
    }
    else if (averageScore >= 60 && averageScore <= 69)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int score;

    cout << "请输入学生的平均成绩(0~100): ";
    cin >> score;

    if (score < 0 || score > 100)
    {
        cout << "输入的成绩无效！" << endl;
    }
    else
    {
        cout << "该学生的分值为: " << qualityPoints(score) << endl;
    }

    return 0;
}