#include <iostream>
using namespace std;
int main()
{
    int weight[5] = {300, 350, 200, 400, 250};
    // 找出并打印最重的小猪

    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (weight[i] > max)
        {
            max = weight[i];
        }
    }

    cout << "最重的小猪体重为：" << max << endl;

    return 0;
}