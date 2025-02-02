#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // random_shuffle()此算法在c++17标准中被移除，因此改用c++11的shuffle
    random_device rd;               // 创建一个随机设备来生成种子
    mt19937 g(rd());                // 使用 random_device 生成的种子来初始化一个梅森旋转算法生成器 mt19937(来自头文件random)
    shuffle(v.begin(), v.end(), g); // 用 g 作为随机数生成器来打乱 v 向量中的元素
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
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