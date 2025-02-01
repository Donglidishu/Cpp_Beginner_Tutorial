#include <iostream>
#include <map>
#include <utility>
using namespace std;

class MyCompare
{
  public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void test01()
{
    map<int, int, MyCompare> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
}

int main()
{
    test01();
    return 0;
}