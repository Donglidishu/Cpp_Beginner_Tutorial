#include <deque>
#include <iostream>
using namespace std;

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d;

    // 尾插
    d.push_back(10);
    d.push_back(20);

    // 头插
    d.push_front(30);
    d.push_front(40);

    printDeque(d);

    // 尾删
    d.pop_back();
    printDeque(d);

    // 头删
    d.pop_front();
    printDeque(d);
}

void test02()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    // 插入
    d.insert(d.begin(), 1000);
    printDeque(d);

    d.insert(d.begin(), 2, 2000);
    printDeque(d);

    // 按照区间插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin(), d2.begin(), d2.end()); // 在d的起始位置插入d2的begin到end区间内的数据
    printDeque(d);
}

void test03()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    // 删除
    d.erase(d.begin());
    printDeque(d);

    // 按区间删除
    d.erase(d.begin(), d.end());
    printDeque(d);

    // 清空
    //  d.clear();
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}