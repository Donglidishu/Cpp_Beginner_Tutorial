#include <iostream>
using namespace std;

// c++中提倡使用多态设计程序架构 因为多态有点很多

// class Calculator
// {
//   public:
//     int getResult(string oper)
//     {
//         if (oper == "+")
//         {
//             return m_Num1 + m_Num2;
//         }
//         else if (oper == "-")
//         {
//             return m_Num1 - m_Num2;
//         }
//         else if (oper == "*")
//         {
//             return m_Num1 * m_Num2;
//         }
//         else
//         {
//             return 0;
//         }
//         // 如果想拓展新的功能，需要修改源码
//         // 真实开发中提倡 开闭原则
//         // 开闭原则：对拓展进行开放 对修改进行关闭
//     }

//     int m_Num1;
//     int m_Num2;
// };

// void test01()
// {
//     // 创建计算器对象
//     Calculator c;
//     c.m_Num1 = 10;
//     c.m_Num2 = 2;

//     cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
//     cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//     cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
// }

// 利用多态实现计算器
// 多态好处：组织结构清晰、可读性强

// 实现计算器抽象类
class abstractCalculator
{
  public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

// 加法计算器类
class addCalculator : public abstractCalculator
{
  public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class subCalculator : public abstractCalculator
{
  public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器类
class mulCalculator : public abstractCalculator
{
  public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    // 多态使用条件：父类指针或者引用指向父类对象
    // 加法计算器
    abstractCalculator *abc = new addCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    // 用完记得释放内存
    delete abc;

    // 减法计算器
    abstractCalculator *abc2 = new subCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc2;

    // 乘法计算器
    abstractCalculator *abc3 = new mulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc3;
}

int main()
{
    // test01();
    test02();
    return 0;
}