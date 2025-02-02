#include <iostream>
using namespace std;
#include <numeric>
#include <vector>
void test01()
{
    vector<int> v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }

    // 第三个参数是起始值
    int total = accumulate(v.begin(), v.end(), 0);

    cout << "total = " << total << endl;
}

int main()
{

    test01();

    return 0;
}