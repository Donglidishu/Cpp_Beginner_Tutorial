#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
    // 判断闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int year;
    cout << "请输入年份：";
    cin >> year;

    if (isLeapYear(year))
    {
        cout << year << " 是闰年。" << endl;
    }
    else
    {
        cout << year << " 不是闰年。" << endl;
    }

    return 0;
}