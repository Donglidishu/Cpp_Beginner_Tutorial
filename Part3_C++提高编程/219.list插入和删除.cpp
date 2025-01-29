#include <iostream>
#include <list>
using namespace std;

// push_back(elem);//在容器尾部加入一个元素
// pop_back();//删除容器中最后一个元素
// push_front(elem);//在容器开头插入一个元素
// pop_front();//从容器开头移除第一个元素
// insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
// insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
// insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
// clear();//移除容器的所有数据
// erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
// erase(pos);//删除pos位置的数据，返回下一个数据的位置。
// remove(elem);//删除容器中所有与elem值匹配的元素。
void printList(const list<int> &L)
{

    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> L;
    // 尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    // 头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    // 尾删
    L.pop_back();
    printList(L);

    // 头删
    L.pop_front();
    printList(L);

    // 插入
    list<int>::iterator i = L.begin();
    L.insert(++i, 1000);
    printList(L);

    // 删除
    i = L.begin();
    L.erase(++i);
    printList(L);

    // 移除
    L.push_back(1000);
    L.push_back(1000);
    L.push_back(1000);
    L.push_back(1000);
    printList(L);
    L.remove(1000); // 会删除队列中所有匹配的元素
    printList(L);

    // 清空
    L.clear();
    printList(L);
}
int main()
{
    test01();
    return 0;
}