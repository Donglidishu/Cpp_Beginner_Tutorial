#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 注意：两个容器必须是有序序列

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
        v1.push_back(i);     // 0~9
        v2.push_back(i + 5); // 5~14
    }

    vector<int> vTarget;
    // 取两个里面较小的值给目标容器开辟空间
    vTarget.resize(min(v1.size(), v2.size()));

    // 返回目标容器的最后一个元素的迭代器地址
    // 获取交集
    vector<int>::iterator itEnd =
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
}

int main()
{

    test01();

    return 0;
}