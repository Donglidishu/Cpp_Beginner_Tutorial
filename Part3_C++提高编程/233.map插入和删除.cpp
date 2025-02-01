#include <iostream>
#include <map>
#include <utility>
using namespace std;

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
    map<int, int> m;

    // 第一种
    m.insert(pair<int, int>(1, 10));

    // 第二种
    m.insert(make_pair(2, 20));

    // 第三种
    m.insert(map<int, int>::value_type(3, 30));

    // 第四种
    m[4] = 40; // 不建议使用该方法进行插入
    //[] 如果key不存在会触发默认构造 m[key]是对容器中元素的一个引用，而map默认在不存在的情况下会通过默认构造创建新元素，影响性能
    // 用途：用key访问value，而不是插入

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3); // 按照key删除
    printMap(m);

    // 清空
    // m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
}

int main()
{
    test01();
    return 0;
}