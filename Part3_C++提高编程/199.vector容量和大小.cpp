#include <iostream>
#include <vector>
using namespace std;

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
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);

    if (v.empty()) // 如果为真则为空
    {
        cout << "容器为空" << endl;
    }
    else
    {
        cout << "容器不为空" << endl;
        cout << "容器的容量为: " << v.capacity() << endl;
        cout << "容器的大小为: " << v.size() << endl;
    }

    // 重新指定大小
    v.resize(15); // 如果重新指定的过长，默认用0填充
    // 或者使用其重载版本为多出的空间赋值
    // v.resize(15, 100);
    printVector(v);

    v.resize(5); // 如果指定的比原来的短，会删除多余部分
    printVector(v);
}

int main()
{
    test01();
    return 0;
}