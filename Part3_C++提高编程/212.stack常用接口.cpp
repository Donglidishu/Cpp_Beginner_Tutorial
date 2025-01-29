#include <iostream>
#include <stack>
using namespace std;

void test01()
{
    // 特点: 符合先进后出数据结构
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "栈的大小: " << s.size() << endl;

    // 只要栈不为空，查看栈顶并执行出栈操作
    while (!s.empty())
    {
        cout << "栈顶: " << s.top() << endl;

        // 出栈
        s.pop();
    }

    cout << "栈的大小: " << s.size() << endl;
}

int main()
{
    test01();
    return 0;
}