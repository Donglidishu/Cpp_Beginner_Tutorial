#include <iostream>
#include <set>
#include <utility>
using namespace std;

void test01()
{
    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(10); // set容器的insert会返回插入结果，表示插入是否成功，返回值是一个pair
    if (ret.second)
    {
        cout << "第一次插入成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret = s1.insert(10); // 会插入失败
    if (ret.second)
    {
        cout << "第二次插入成功" << endl;
    }
    else
    {
        cout << "第二次插入失败" << endl;
    }

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10); // 允许插入重复数据
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}