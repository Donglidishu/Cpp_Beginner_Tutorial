#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string topics[5] = {"Topic 1", "Topic 2", "Topic 3", "Topic 4", "Topic 5"};
    int responses[5][10] = {0};         // 每个问题的评分记录，5行10列
    int totalResponses[5] = {0};        // 每个问题的总分
    double averageResponses[5] = {0.0}; // 每个问题的平均分

    // 数据输入
    for (int user = 0; user < 10; user++)
    {
        cout << "User " << user + 1 << "，请对以下问题进行评分 (1-10):\n";
        for (int question = 0; question < 5; question++)
        {
            cout << topics[question] << ": ";
            int score;
            cin >> score;

            // 检查评分有效性
            while (score < 1 || score > 10)
            {
                cout << "无效评分，请输入 1 到 10 的数字: ";
                cin >> score;
            }

            responses[question][score - 1]++;  // 累计该评分
            totalResponses[question] += score; // 累计总分
        }
    }

    // 计算平均分
    for (int i = 0; i < 5; i++)
    {
        averageResponses[i] = static_cast<double>(totalResponses[i]) / 10.0;
    }

    // 输出表格
    cout << "\n汇总统计结果:\n";
    cout << setw(10) << "问题";
    for (int score = 1; score <= 10; score++)
    {
        cout << setw(6) << score;
    }
    cout << setw(8) << "总分" << setw(10) << "平均分\n";

    for (int i = 0; i < 5; i++)
    {
        cout << setw(10) << topics[i];
        for (int score = 0; score < 10; score++)
        {
            cout << setw(6) << responses[i][score];
        }
        cout << setw(8) << totalResponses[i] << setw(10) << fixed << setprecision(2) << averageResponses[i] << "\n";
    }

    // 找出总分最高和最低的问题
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < 5; i++)
    {
        if (totalResponses[i] > totalResponses[maxIndex])
        {
            maxIndex = i;
        }
        if (totalResponses[i] < totalResponses[minIndex])
        {
            minIndex = i;
        }
    }

    cout << "\n总分最高的是: " << topics[maxIndex] << "，总分为 " << totalResponses[maxIndex] << "\n";
    cout << "总分最低的是: " << topics[minIndex] << "，总分为 " << totalResponses[minIndex] << "\n";

    return 0;
}