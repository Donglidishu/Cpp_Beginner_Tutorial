#include <iostream>
#include <map>
#include <utility>
using namespace std;

// map中所有元素都是pair
// pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
// 所有元素都会根据元素的键值自动排序

// 本质：
// map/multimap属于关联式容器，底层结构是用二叉树实现。

// 优点：
// 可以根据key值快速找到value值

// map和multimap区别：
// map不允许容器中有重复key值元素
// multimap允许容器中有重复key值元素

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> mp;
    // 会自动按照key值进行排序(不是value)
    mp.insert(pair<int, int>(1, 10)); // 向map中插入元素
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(4, 40));
    mp.insert(pair<int, int>(3, 30));

    printMap(mp);

    // 拷贝构造
    map<int, int> mp2(mp);
    printMap(mp2);

    // 赋值
    map<int, int> mp3;
    mp3 = mp2;
    printMap(mp3);
}

int main()
{
    test01();
    return 0;
}