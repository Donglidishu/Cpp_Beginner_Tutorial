#include <iostream>
using namespace std;
int main()
{
    //引用语法：int &别名 = 原名

    int a = 10;
    int &b = a;
    // int &b; 错误 引用必须要初始化
    //引用一旦初始化后就不可以更改 例如b已经作为a的别名，不可以把b更改为c的别名

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 20;
    cout << "b after change" << b << endl;


    return 0;
}