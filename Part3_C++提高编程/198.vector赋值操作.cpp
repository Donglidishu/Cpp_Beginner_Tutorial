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

    // 赋值 operator=
    vector<int> v2;
    v2 = v;
    printVector(v2);

    // assign
    vector<int> v3;
    v3.assign(v2.begin(), v2.end()); // 左闭右开区间
    printVector(v3);

    // n个elem
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}