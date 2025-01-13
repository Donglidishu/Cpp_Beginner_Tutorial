#include <iostream>
using namespace std;

class abstractDrinking
{
  public:
    virtual ~abstractDrinking()
    {
        cout << "父类析构调用" << endl;
    }

    // 煮水
    virtual void Boil() = 0;

    // 冲泡
    virtual void Brew() = 0;

    // 倒入杯中
    virtual void pourInCup() = 0;

    // 辅料
    virtual void putSomething() = 0;

    // 制作饮品
    virtual void makeDrink()
    {
        Boil();
        Brew();
        pourInCup();
        putSomething();
    }
};

// 制作咖啡
class Coffee : public abstractDrinking
{
  public:
    void Boil()
    {
        cout << "煮水" << endl;
    }
    void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    void pourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    void putSomething()
    {
        cout << "加入糖" << endl;
    }
};

class Tea : public abstractDrinking
{
  public:
    void Boil()
    {
        cout << "煮水" << endl;
    }
    void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    void pourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    void putSomething()
    {
        cout << "加入枸杞" << endl;
    }
};

// 制作函数
void doWork(abstractDrinking *abs) // abstractDrinking *abs = new Coffee (父类指针指向子类对象)
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    // 制作咖啡
    doWork(new Coffee);

    cout << "--------------------" << endl;

    // 制作茶叶
    doWork(new Tea);
}

int main()
{
    test01();
    return 0;
}