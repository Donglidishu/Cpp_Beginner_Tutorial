#include <iostream>
using namespace std;

// 1.构造函数的分类和调用
// 分类
//   按照参数分类：无参构造(默认构造)和有参构造
//   按照类型分类：普通构造 拷贝构造
class Person
{
  public:
    // 构造函数
    Person()
    {
        cout << "Person无参构造函数调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "Person有参构造函数调用" << endl;
    }

    // 拷贝构造函数
    Person(const Person &p) // const防止对原对象造成修改
    {
        // 将传入人身上的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person拷贝构造函数调用" << endl;
    }

    int age;

    // 析构函数
    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
};

// 调用
void test01()
{
    // 1.括号法
    Person p1;     // 默认构造函数
    Person p2(10); // 有参构造函数
    Person p3(p2); // 拷贝构造函数

    // 注意事项
    //   调用默认构造函数的时候不要加() 否则会被编译器认为是函数的声明

    // 2.显式法
    Person p4;
    Person p5 = Person(10); // 有参构造
    Person p6 = Person(p2); // 拷贝构造 其中等号右边的Person(p2)叫做匿名对象 执行完当前行系统会立即回收内存 等号左边则为对象名

    // 注意事项
    //   不要利用拷贝构造函数 初始化匿名对象 编译器会认为 Person(p3) === Person p3

    // 3.隐式转换法
    Person p7 = 10; // 有参构造 相当于写了Person p7 = Person(10);
    Person p8 = p7; // 拷贝构造 相当于写了Person p8 = Person(p7);
}

int main()
{
    test01();

    return 0;
}
