#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 注意：在无序序列中不可用
// 二分查找返回布尔类型 用于查找元素是否存在

void test01()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 二分查找
    bool ret = binary_search(v.begin(), v.end(), 2);
    if (ret)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{

    test01();
    return 0;
}