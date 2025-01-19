#include <iostream>
using namespace std;
int main()
{
    char a;
    cout << "请输入任意字符：" << endl;
    cin >> a;
    cout << "该字符强转换为int时为: " << static_cast<int>(a) << endl;

    return 0;
}
