#include <iostream>
#include <string>
using namespace std;

// 三种访问权限
// 公共权限 public   成员类内/类外均可以访问
// 保护权限 protect  成员类内可以访问 类外不行   //只能被父类及其子类访问，不能被外部直接访问
// 私有权限 private  成员类内可以访问 类外不行   //只能被父类本身访问，子类和外部均无法直接访问(在继承中详解)

class sampleClass
{
  public:
    string m_name;

  protected:
    string m_car;

  private:
    int m_password;

  public:
    void func()
    {
        m_name = "zhangsan";
        m_car = "m4gt3";
        m_password = 123;
    }
};

int main()
{
    sampleClass a1;
    a1.m_name = "张三";
    // a1.m_car = 'car'; //成员 "sampleClass::m_car" (已声明 所在行数:16) 不可访问C/C++(265)
    // a1.m_password = 1111; //成员 "sampleClass::m_password" (已声明 所在行数:19) 不可访问C/C++(265)
    a1.func();

    return 0;
}