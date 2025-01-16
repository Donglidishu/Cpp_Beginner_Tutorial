#include <iostream>
using namespace std;

// 抽象不同零件类
// 抽象cpu类
class CPU
{
  public:
    virtual void calculate() = 0;
    virtual ~CPU() {};
};

// 抽象GPU类
class GPU
{
  public:
    virtual void display() = 0;
    virtual ~GPU() {};
};

// 抽象存储类
class Memory
{
  public:
    virtual void storage() = 0;
    virtual ~Memory() {};
};

// 电脑类
class Computer
{
  public:
    ~Computer()
    {
        if (m_CPU != nullptr)
        {
            delete m_CPU; // 当调用 delete m_CPU 时，C++ 只会调用 CPU 基类的析构函数，而不会调用派生类（如 IntelCPU 或 AMDCPU）的析构函数，这可能导致资源泄漏或未定义行为，因此基类需要虚析构函数
            m_CPU = nullptr;
        }
        if (m_VideoCard != nullptr)
        {
            delete m_VideoCard;
            m_VideoCard = nullptr;
        }
        if (m_Mem != nullptr)
        {
            delete m_Mem;
            m_Mem = nullptr;
        }
    }

    Computer(CPU *cpu, GPU *gpu, Memory *mem)
    {
        m_CPU = cpu;
        m_VideoCard = gpu;
        m_Mem = mem;
    }

    // 提供工作的函数
    void work()
    {
        m_CPU->calculate();
        m_VideoCard->display();
        m_Mem->storage();
    }

  private:
    CPU *m_CPU;       // cpu的零件指针
    GPU *m_VideoCard; // 显卡的零件指针
    Memory *m_Mem;    // 内存条零件指针
};

// 具体厂商
// Intel
class IntelCPU : public CPU
{
  public:
    virtual void calculate()
    {
        cout << "Intel正在计算" << endl;
    }
};

class IntelVideoCard : public GPU
{
  public:
    virtual void display()
    {
        cout << "Intel显卡正在显示" << endl;
    }
};

class IntelMemory : public Memory
{
  public:
    virtual void storage()
    {
        cout << "Intel开始存储" << endl;
    }
};

// AMD
class AMDCPU : public CPU
{
  public:
    virtual void calculate()
    {
        cout << "AMD正在计算" << endl;
    }
};

class AMDVideoCard : public GPU
{
  public:
    virtual void display()
    {
        cout << "AMD显卡正在显示" << endl;
    }
};

class AMDMemory : public Memory
{
  public:
    virtual void storage()
    {
        cout << "AMD开始存储" << endl;
    }
};

void test01()
{
    // 第一台电脑零件
    CPU *intelCPU = new IntelCPU;
    GPU *intelVideoCard = new IntelVideoCard;
    Memory *intelMemory = new IntelMemory;

    // 创建第一台电脑
    Computer *intelComputer = new Computer(intelCPU, intelVideoCard, intelMemory);
    cout << "intelComputer: " << endl;
    intelComputer->work();
    delete intelComputer;

    cout << "----------------------" << endl;

    // 创建第二台电脑
    Computer *amdComputer = new Computer(new AMDCPU, new AMDVideoCard, new AMDMemory);
    cout << "amdComputer: " << endl;
    amdComputer->work();
    delete amdComputer;

    cout << "----------------------" << endl;

    // 创建第二台电脑
    Computer *mixComputer = new Computer(new IntelCPU, new AMDVideoCard, new IntelMemory);
    cout << "mixComputer: " << endl;
    mixComputer->work();
    delete mixComputer;
}

int main()
{
    test01();
    return 0;
}