#include <iostream>
#include <map>
using namespace std;

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    cout << "m.size() = " << m.size() << endl;
    if (m.empty())
    {
        cout << "m is empty" << endl;
    }
    else
    {
        cout << "m is not empty" << endl;
        cout << "size of m: " << m.size() << endl;
    }
}

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test02()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));

    map<int, int> m2;
    m2.insert(pair<int, int>(5, 50));
    m2.insert(pair<int, int>(6, 60));
    m2.insert(pair<int, int>(7, 70));
    m2.insert(pair<int, int>(8, 80));

    cout << "交换前" << endl;
    printMap(m);
    printMap(m2);

    cout << "交换后" << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);
}
int main()
{
    // test01();
    test02();
    return 0;
}