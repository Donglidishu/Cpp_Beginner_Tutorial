#include <iostream>
using namespace std;
// 1.new基本语法
int *test01()
{
    int *p = new int(10);
    return p;
}

// 2.使用new开辟数组
void test02()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    delete[] arr;//释放堆区数组
}

int main()
{
    int *p = test01();
    cout << *p << endl;
    cout << *p << endl;
    delete p; // 释放new开辟的内存空间，之后再对p进行输出则为无定义的p

    test02();
    

    return 0;
}