#include <iostream>
using namespace std;
int main()
{
    // 1条语句1个流插入运算符
    cout << "1 2 3 4";

    // 1条语句四个流插入运算符
    cout << "1 " << "2 " << "3 " << "4 ";

    // 4条语句
    cout << "1 " << endl;
    cout << "2 " << endl;
    cout << "3 " << endl;
    cout << "4 " << endl;

    return 0;
}