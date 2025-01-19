#include <iostream>
using namespace std;
int main()
{
    // 1.创建bool数据类型（布尔类型只要是非零值都代表真）
    bool flag = true; // true会输出1
    cout << flag << endl;

    flag = false; // false会输出0
    cout << flag << endl;

    // 2.查看bool类型所占内存空间
    cout << "bool类型所占内存空间:" << sizeof(bool) << endl;
    // 所占内存空间=1

    return 0;
}