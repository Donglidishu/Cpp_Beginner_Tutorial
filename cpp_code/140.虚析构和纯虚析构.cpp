#include <iostream>
#include <string>
using namespace std;

class Animal
{
  public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }
    // 利用虚析构可以解决父类指针释放子类对象是不干净的问题
    // 如果子类没有堆区数据 可以不写为虚析构或纯虚析构

    // virtual ~Animal()
    // {
    //     cout << "Animal析构函数调用" << endl;
    // }

    // 纯虚析构 需要声明也需要实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;

    // 纯虚函数
    virtual void speak() = 0;
};

Animal::~Animal()
{
}

class Cat : public Animal
{
  public:
    Cat(string name)
    {
        m_Name = new string(name);
    }

    ~Cat()
    {
        if (m_Name != nullptr)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = nullptr;
        }
    }

    virtual void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }

    string *m_Name;
};

void test01()
{
    Animal *ani = new Cat("Tom");
    ani->speak();
    // 父类指针在析构的时候，不会调用子类的析构函数，导致子类如果有堆区属性，会造成内存泄漏
    delete ani;
}

int main()
{
    test01();
    return 0;
}