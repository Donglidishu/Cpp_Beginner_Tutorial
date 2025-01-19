#include <iostream>
using namespace std;

// 多态

// 动物类
class Animal
{
  public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

// 猫类
class cat : public Animal
{
  public:
    void speak() // 此处virtual关键字可加可不加
    {
        cout << "小猫在说话" << endl;
    }
};

// 狗类
class dog : public Animal
{
  public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

// 执行说话的函数
// 地址早绑定 在编译阶段就确定函数地址
// 如果想执行让猫说话，这个函数地址就不能早绑定 需要在运行阶段进行绑定 地址晚绑定

// 动态多态满足条件
// 1.有继承关系
// 2.子类重写父类中的虚函数
// 重写 函数返回值类型 函数名 参数列表 完全相同

// 动态多态的使用
// 父类的指针或者引用 指向子类对象

void doSpeak(Animal &animal) // Animal &animal = cat
{
    animal.speak();
}

void test01()
{
    cat cat;
    doSpeak(cat);

    dog dog;
    doSpeak(dog);
}
int main()
{
    test01();
    return 0;
}