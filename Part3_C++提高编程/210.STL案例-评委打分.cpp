#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// 创建五名选手, 放到vector中, 遍历vector容器, 取出来每一个选手, 执行for循环, 可以把10个评分打分存到deque容器中
// sort算法对deque容器中分数排序, 去除最高和最低分, deque容器遍历一遍, 累加总分, 获取平均分

class Person
{
  public:
    Person(string name, deque<double> scoreContainer, double average)
        : m_Name(name), m_ScoreContainer(scoreContainer), m_Average(average)
    {
    }

  public:
    string m_Name;
    deque<double> m_ScoreContainer;
    double m_Average;
};

void printInfo(const vector<Person> &container)
{
    cout << "五位选手的信息如下: " << endl;
    for (int i = 0; i < container.size(); i++)
    {
        cout << container[i].m_Name << " " << container[i].m_Average << endl;
    }
}

int main()
{
    vector<Person> personContainer;

    // 进行选手信息录入
    for (int i = 0; i < 5; i++)
    {
        string playerName;         // 存放姓名
        deque<double> playerScore; // 存放10个评分数据

        cout << "请输入第 " << i + 1 << " 名选手的姓名: ";
        cin >> playerName;
        cout << endl;

        double score; // 存放单个评委的数据
        for (int j = 0; j < 10; j++)
        {
            cout << "请输入第 " << j + 1 << " 名评委的评分: ";
            cin >> score;
            playerScore.push_back(score);
        }

        // 计算总分
        sort(playerScore.begin(), playerScore.end());
        playerScore.pop_back();  // 去掉最大值
        playerScore.pop_front(); // 去掉最小值

        double totalScore = 0;
        // 计算平均分
        for (deque<double>::iterator de = playerScore.begin(); de != playerScore.end(); de++)
        {
            totalScore += *de;
        }

        // 将信息保存到表
        personContainer.push_back(Person(playerName, playerScore, totalScore / 8));
    }

    printInfo(personContainer);

    return 0;
}