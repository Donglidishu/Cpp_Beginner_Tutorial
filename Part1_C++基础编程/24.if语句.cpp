#include <iostream>
using namespace std;
int main()
{
    // 单行if语句
    int score = 0;
    cout << "输入你的高考成绩：" << endl;
    cin >> score;
    /*

    if (score >= 600)
    {
        cout << "text" << endl;
    }

    //多行if语句
    if (score >= 600)
    {
        cout << "text" << endl;
    }
    else
    {
        cout << "text" << endl;
    }


    //多条件if语句
    if (score >= 593)
    {
        cout << "恭喜你考上南京工业大学！" << endl;
    }
    else if (score > 500)
    {
        cout << "恭喜你考上二本" << endl;
    }
    else if (score > 400)
    {
        cout << "恭喜你上大专" << endl;
    }
    else
    {
        cout << "废物" << endl;
    }

    */

    // 嵌套if语句
    if (score > 600)
    {
        if (score >= 700)
        {
            cout << "恭喜你可以考上清华北大！" << endl;
        }
        else if (score > 650)
        {
            cout << "恭喜你可以考上人大！" << endl;
        }

        else
        {
            cout << "恭喜你考上南京工业大学！" << endl;
        }
    }
    else
    {
        cout << "你只能上带专了" << endl;
    }

    return 0;
}