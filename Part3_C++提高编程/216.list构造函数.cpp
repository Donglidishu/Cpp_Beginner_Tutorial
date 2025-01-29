#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &L)
{
    for (list<int>::const_iterator li = L.begin(); li != L.end(); li++)
    {
        cout << *li << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    printList(l);

    // 区间方式构造
    list<int> l2(l.begin(), l.end());
    printList(l2);

    // 拷贝构造
    list<int> l3(l2);
    printList(l3);

    // n个elem
    list<int> l4(10, 1000);
    printList(l4);
}

int main()
{
    test01();
    return 0;
}