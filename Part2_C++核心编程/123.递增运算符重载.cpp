#include <iostream>
#include <ostream>
using namespace std;

// 重载递增运算符

// 自定义整型

class myInteger
{
    friend ostream &operator<<(ostream &cout, myInteger myint);

  public:
    myInteger()
    {
        m_Num = 0;
    }
    // 重载++运算符(前置) 返回引用为了一直对一个数据进行递增操作
    myInteger &operator++()
    {
        m_Num++;
        return *this;
    }

    // 重载++运算符(后置) 返回值而不是引用
    // int代表占位参数，可以用于区分前置和后置递增
    myInteger operator++(int)
    {
        // 先 记录当时结果
        myInteger temp = *this;

        // 后 递增
        m_Num++;

        // 最后将记录结果做返回
        return temp;
    }

  private:
    int m_Num;
};

// 重载左移运算符
ostream &operator<<(ostream &cout, myInteger myint)
{
    cout << myint.m_Num << endl;
    return cout;
}

void test01()
{
    myInteger myint;
    cout << myint << endl;
    cout << ++myint << endl;
}

void test02()
{
    myInteger myint;
    cout << myint << endl;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}