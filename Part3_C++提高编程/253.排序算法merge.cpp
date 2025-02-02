#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void myprint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    // 目标容器
    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size()); // 注意要先分配空间

    // 合并的两个容器需要是有序序列，且同为升/降序，合并后的序列仍然是有序序列
    // 即合并后排序方式保持一致
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), myprint);
}

int main()
{
    test01();
    return 0;
}