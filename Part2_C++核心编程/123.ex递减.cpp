#include <iostream>
#include <ostream>
using namespace std;

class myInteger
{
    friend ostream &operator<<(ostream &cout, myInteger myint);

  public:
    myInteger()
    {
        m_Num = 3;
    }

    // 递减运算符重载(前置)
    myInteger &operator--()
    {
        m_Num--;
        return *this;
    }

    // 递减运算符重载(后置)
    myInteger operator--(int)
    {
        myInteger temp = *this;
        m_Num--;
        return temp;
    }

  private:
    int m_Num;
};

ostream &operator<<(ostream &cout, myInteger myint)
{
    cout << myint.m_Num << endl;
    return cout;
}

void test01()
{
    myInteger myint;
    cout << myint << endl;
    cout << --myint << endl;
}

void test02()
{
    myInteger myint;
    cout << myint << endl;
    cout << myint-- << endl;
    cout << myint << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}