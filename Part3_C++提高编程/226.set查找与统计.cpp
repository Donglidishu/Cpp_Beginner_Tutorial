#include <iostream>
#include <set>
using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    printSet(s1);

    set<int>::iterator pos = s1.find(300); // find查找 如果找到了，则返回该元素的迭代器，若没找到，返回s1.end()
    if (pos != s1.end())
    {
        cout << "找到了元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
}

void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    printSet(s1);
    int num = s1.count(30);                // count统计元素个数
    cout << "30的个数为: " << num << endl; // set容器中只会是0或者1，因为set不允许重复元素
}

int main()
{
    // test01();
    test02();
    return 0;
}