#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 10;
    int c = 0;
    int d = 0;
    // c++中 非0即为真
    // 1.！非 a为假 !a 为真

    cout << !a << endl;
    cout << !!a << endl;

    // 2.&& 与 a&&b ab都为真结果为真，其中一个为假就是假
    cout << (a && b) << endl;
    cout << (a && c) << endl;

    // 3.|| 或 a||b a或b有一个为真则为真，二者均为假才是假
    cout << (a || b) << endl;
    cout << (a || c) << endl;
    cout << (c || d) << endl;

    return 0;
}