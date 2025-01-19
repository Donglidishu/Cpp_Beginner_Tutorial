#include <iostream>
#include <string>
using namespace std;

// 函数调用运算符重载

// 打印输出类
class myPrint
{
  public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void test01()
{
    myPrint print;
    print("helloword"); // 由于使用起来非常类似于函数调用，因此成为仿函数
}

// 仿函数非常灵活，没有固定写法
// 在后续stl课程中会使用，此处只做了解
class myAdd
{
  public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    myAdd myadd;
    int ret = myadd(100, 100);
    cout << "ret = " << ret << endl;

    // 匿名函数对象
    cout << myAdd()(100, 100) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}