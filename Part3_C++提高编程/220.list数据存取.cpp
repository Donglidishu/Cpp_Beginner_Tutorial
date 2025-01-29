#include <iostream>
using namespace std;

#include <list>

// 数据存取
void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // cout << L1.at(0) << endl;//错误 不支持at访问数据
    // cout << L1[0] << endl; //错误  不支持[]方式访问数据

    // list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
    cout << "第一个元素为： " << L1.front() << endl;
    cout << "最后一个元素为： " << L1.back() << endl;

    // list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = L1.begin();
    // it = it + 1;//错误，不可以跳跃访问，即使是+1
    it++;
    it--; // 可以支持
}

int main()
{

    test01();

    return 0;
}