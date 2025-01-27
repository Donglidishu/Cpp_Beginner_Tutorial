#include <iostream>
#include <vector>
using namespace std;

// vector构造函数

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v; // 默认构造 无参
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);

    // 通过区间方式进行构造
    vector<int> v2(v.begin(), v.end());
    printVector(v);

    // n个elem方式构建
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}