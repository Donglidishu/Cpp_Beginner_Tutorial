#include <iostream>
using namespace std;

int secondsSinceLast12(int hours, int minutes, int seconds)
{
    // 将小时数转换为 12 小时制
    hours = hours % 12;

    int totalSeconds = hours * 3600 + minutes * 60 + seconds;

    return totalSeconds;
}

int main()
{
    int hours, minutes, seconds;

    cout << "请输入当前时间（小时 分钟 秒）：";
    cin >> hours >> minutes >> seconds;

    int result = secondsSinceLast12(hours, minutes, seconds);

    cout << "距离上一次 12 点整的秒数为：" << result << " 秒" << endl;

    return 0;
}