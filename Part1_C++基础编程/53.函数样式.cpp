#include <iostream>
using namespace std;

// 1.无参无返
void test01()
{
    cout << "test01" << endl;
}

// 2.无参有返
int test02()
{
    cout << "test02" << endl;
    return 1000;
}

// 3.有参无反
void test03(int a)
{
    cout << "test03:" << a << endl;
}

// 4.有参有反
int test04(int b)
{
    cout << "test04:" << b << endl;
    return b;
}

int main()
{
    // 1.无参无返
    test01();

    // 2.无参有返
    test02();

    // 3.有参无反
    int num1 = 0;
    test03(num1);

    // 4.有参有反
    int num2 = 10;
    test04(num2);

    return 0;
}
