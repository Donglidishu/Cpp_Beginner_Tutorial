#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 注意：两个容器必须是有序序列
// 差集的定义: 对于两个有序集合 A 和 B，差集 A - B 是一个集合，它包含所有属于 A 且不属于 B 的元素

class myPrint
{
  public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    // 最特殊情况 两个容器没有交集
    //  取两个里面较大的值给目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));

    // 返回目标容器的最后一个元素的迭代器地址
    cout << "v1与v2的差集为: " << endl;
    vector<int>::iterator itEnd =
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;

    cout << "v2与v1的差集为:  " << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
}

int main()
{

    test01();

    return 0;
}