#include <iostream>
#include <vector>
using namespace std;

// 插入删除

//   push_back(ele);                                  尾部插入元素ele
//   pop_back();                                      删除最后一个元素
//   insert(const_iterator pos, ele);                 迭代器指向位置pos插入元素ele
//   insert(const_iterator pos, int count,ele);       迭代器指向位置pos插入count个元素ele
//   erase(const_iterator pos);                       删除迭代器指向的元素
//   erase(const_iterator start, const_iterator end); 删除迭代器从start到end之间的元素
//   clear();                                         删除容器中所有元素

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v;
    // 尾插
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    printVector(v);

    // 尾删
    v.pop_back();
    printVector(v);

    // 插入 第一个参数是迭代器
    v.insert(v.begin(), 100); // 在迭代器位置插入100
    printVector(v);

    v.insert(v.begin(), 2, 1000); // 在迭代器位置插入2个1000
    printVector(v);

    // 删除 参数是迭代器
    v.erase(v.begin());
    printVector(v);

    v.erase(v.begin(), v.begin() + 1);
    printVector(v);

    // 清除
    v.clear();
    printVector(v);
}

int main()
{
    test01();
    return 0;
}