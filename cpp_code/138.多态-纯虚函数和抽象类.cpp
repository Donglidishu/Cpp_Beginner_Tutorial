#include <iostream>
using namespace std;

// 纯虚函数和抽象类

class Base
{
  public:
    // 纯虚函数
    // 只要有一个纯虚函数，这个类称为抽象类
    // 抽象类的特点：1.无法实例化对象 2.抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;

    // 纯虚析构函数，用于释放内存，在delete时，会依次调用子类和父类的析构
    // 当通过基类指针（例如 Base* b）操作派生类对象（例如 Son）时，如果基类的析构函数不是虚函数，销毁对象时会调用基类的析构函数，而不会调用子类的析构函数，这可能会导致子类资源未正确释放
    virtual ~Base() = 0;
};

class Son : public Base
{
  public:
    void func() override // override用于显式地标识子类重写（覆盖）父类的虚函数。它的作用是让编译器帮助你检查子类是否正确地覆盖了父类的虚函数
    {
        cout << "func函数调用" << endl;
    }
};

void test01()
{
    // Base b1;  抽象类无法实例化对象
    // new Base; 抽象类无法实例化对象
    // Son s;//必须重写父类纯虚函数
    Base *b = new Son;
    b->func();
    delete b;
}

int main()
{
    test01();
    return 0;
}