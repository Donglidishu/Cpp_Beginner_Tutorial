#include <iostream>
using namespace std;

#include <set>

class MyCompare
{
  public:
    bool operator()(const int &v1, const int &v2) const // 由于 std::set 会传递 const 左值给比较器，operator() 必须能够接受 const 左值。没有 const 的 operator() 无法处理这种情况，因此编译器报错
    {
        return v1 > v2;
    }
};
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    // 默认从小到大
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 指定排序规则为从大到小
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
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