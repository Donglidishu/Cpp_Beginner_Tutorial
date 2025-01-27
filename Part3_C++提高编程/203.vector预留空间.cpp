#include <iostream>
using namespace std;
#include <vector>

void test01()
{
    vector<int> v;

    // 预留空间
    v.reserve(100000); // 一开始有预留，就可以只用一次开辟
    // 若没有预留num最后输出的是18次

    int num = 0; // 统计开辟次数
    int *p = nullptr;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl;
}

int main()
{

    test01();

    return 0;
}
