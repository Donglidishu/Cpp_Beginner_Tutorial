#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "请输入员工数量: ";
    cin >> N;

    int countArr[9] = {0};
    int salary = 0;
    int sales = 0;
    cout << "请依次输入每位员工的销售额(输入完一人按一次回车): ";
    for (int i = 0; i < N; i++)
    {
        cin >> sales;
        salary = 200 + sales * 0.09;
        if (salary < 300)
        {
            countArr[0]++;
        }
        else if (salary < 400)
        {
            countArr[1]++;
        }
        else if (salary < 500)
        {
            countArr[2]++;
        }
        else if (salary < 600)
        {
            countArr[3]++;
        }
        else if (salary < 700)
        {
            countArr[4]++;
        }
        else if (salary < 800)
        {
            countArr[5]++;
        }
        else if (salary < 900)
        {
            countArr[6]++;
        }
        else if (salary < 1000)
        {
            countArr[7]++;
        }
        else
        {
            countArr[8]++;
        }
    }

    // 输出统计结果
    cout << "各薪资区间获得人数统计如下:" << endl;
    cout << "200~299美元: " << countArr[0] << "人" << endl;
    cout << "300~399美元: " << countArr[1] << "人" << endl;
    cout << "400~499美元: " << countArr[2] << "人" << endl;
    cout << "500~599美元: " << countArr[3] << "人" << endl;
    cout << "600~699美元: " << countArr[4] << "人" << endl;
    cout << "700~799美元: " << countArr[5] << "人" << endl;
    cout << "800~899美元: " << countArr[6] << "人" << endl;
    cout << "900~999美元: " << countArr[7] << "人" << endl;
    cout << "1000美元及以上: " << countArr[8] << "人" << endl;

    return 0;
}