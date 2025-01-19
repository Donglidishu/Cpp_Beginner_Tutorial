#include <iostream>
using namespace std;

int main()
{
    /*
        表达式:
        switch(表达式)
        {
            case 结果1：执行语句; break;
            case 结果2：执行语句; break;
            case 结果3：执行语句; break;
            ……
            default:执行语句; break;

        }
    */

    // 给电影打分
    // 10~9 经典
    // 8~7 非常好
    // 6~5 一般
    // 5以下 烂片

    // 提示用户给电影打分
    cout << "请给电影进行打分：" << endl;

    // 进行打分
    int score = 0;
    cin >> score;

    // 根据分数显示结果
    switch (score)
    {
    case 10:
    case 9:
        cout << "经典" << endl;
        break; // 退出当前分支

    case 8:
    case 7:
        cout << "非常好" << endl;
        break;

    case 6:
    case 5:
        cout << "一般" << endl;
        break;

    default:
        cout << "烂片" << endl;
        break;
    }
    // if和switch区别：
    // switch缺点，判断时候只能是整型或者字符型，不可以是一个区间 如果使用if语句可以写成if (score >= 9 && score <= 10)
    // 优点：结构清晰，执行效率高

    return 0;
}