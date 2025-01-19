#include <iostream>
using namespace std;
int main()
{
    //输出三名同学的总成绩
    int score[3][3] =
    {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += score[i][j];
        }
        cout << "第" << i + 1 << "个人的总分为：" << sum << endl;
    }
    

    
    
    
    return 0;
}