#include <iostream>
#include <string>
using namespace std;

// 1.函数对象在调用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
  public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
}

// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
  public:
    MyPrint()
        : count(0)
    {
    }

  public:
    void operator()(string text)
    {
        cout << text << endl;
        this->count++;
    }

    int count; // 自己的状态，记录调用了多少次
};

void test02()
{
    MyPrint myprint;
    myprint("hello");
    myprint("hello");
    myprint("hello");
    myprint("hello");
    myprint("hello");
    cout << myprint.count << endl; // 因为对象没有被删除，所以count可以用来计数
}

// 3.函数对象可以作为参数传递
void doPrint(MyPrint &mp, string text)
{
    mp(text);
}

void test03()
{
    MyPrint myprint;
    doPrint(myprint, "helloC++");
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}