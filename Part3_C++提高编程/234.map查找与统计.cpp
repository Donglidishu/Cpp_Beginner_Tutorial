#include <iostream>
#include <map>
using namespace std;

void test01()
{
    // 查找
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));

    map<int, int>::iterator pos = m.find(3); // 返回迭代器
    if (pos != m.end())
    {
        cout << "查到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = m.count(3); // 对于map容器而言只能是0或1(和set一样) multimap才会大于1
    cout << "num = " << num << endl;
}

int main()
{
    test01();
    return 0;
}