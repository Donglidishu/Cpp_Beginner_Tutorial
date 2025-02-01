#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 仿函数 返回值类型是bool 成为谓词
// 一元谓词

class GreaterFive
{
  public:
    bool operator()(int val) // 如果是一个参数则为一元谓词
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 查找容器中 有没有大于5的数字
    // GreaterFive()匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive()); // 返回的是迭代器
    if (it == v.end())
    {
        cout << "没有找到大于五的数字" << endl;
    }
    else
    {
        cout << "找到大于五的数字 " << *it << endl;
    }
}

int main()
{
    test01();
    return 0;
}