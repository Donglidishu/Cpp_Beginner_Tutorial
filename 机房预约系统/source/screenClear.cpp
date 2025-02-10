#include "screenClear.h"
#include <iostream>
using namespace std;

// 清屏操作
void screenClear()
{
#ifdef _WIN32
    system("cls");
#else
    cout << "按回车继续...";
    cin.get();
    system("clear");
#endif
}