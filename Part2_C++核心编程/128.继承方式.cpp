#include <iostream>
using namespace std;

// 继承方式
class Base1
{
  public:
    int m_A;

  protected:
    int m_B;

  private:
    int m_C;
};

// 公共继承
class Son1 : public Base1
{
  public:
    void func()
    {
        m_A = 10; // 父类中公共权限成员 到子类中依然是公共权限
        m_B = 10; // 父类中保护权限成员 到子类中依然是保护权限
        // m_C 父类中私有权限成员 子类访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 100; 保护权限类外访问不到
}

// 保护继承
class Base2
{
  public:
    int m_A;

  protected:
    int m_B;

  private:
    int m_C;
};

class Son2 : protected Base2
{
  public:
    void func()
    {
        m_A = 10; // 保护继承 父类中公共成员，到子类中变为保护权限
        m_B = 10; // 仍然是保护权限
        // m_C = 10; 父类中私有成员访问不到
    }
};

void test02()
{
    Son2 s2;
    // s2.m_A = 100; 保护权限，类外访问不到
    // s2.m_B = 100; 保护权限，类外访问不到
}

// 私有继承
class Base3
{
  public:
    int m_A;

  protected:
    int m_B;

  private:
    int m_C;
};

class Son3 : private Base3
{
  public:
    void func()
    {
        m_A = 10; // 私有继承 父类中公共成员，到子类中变为私有权限
        m_B = 10; // 私有继承 父类中公共成员，到子类中变为私有权限
        // m_C = 10; 父类中私有成员访问不到
    }
};

class GrandSon3 : public Son3
{
  public:
    void func()
    {
        // m_A = 1000; //到了Son3中变为私有，即使是儿子也访问不到
        // m_B = 1000; //到了Son3中变为私有，即使是儿子也访问不到
    }
};

void test03()
{
    Son3 s3;
    // s3.m_A = 100; 私有成员类外访问不到
    // s3.m_B = 100; 私有成员类外访问不到
}

int main()
{
    cout << "用于忽略警告" << endl;
    return 0;
}