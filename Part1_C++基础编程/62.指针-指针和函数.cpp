#include <iostream>
using namespace std;

void swap01(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap02(int *p1, int *p2) // 此处*p1中的’*‘是为了指示p1是一个指针，而不是解引用的意思
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    // 1.值传递(不改变实参)
    int a = 10;
    int b = 20;
    swap01(a, b);
    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;

    // 2.地址传递(可改变实参)

    int c = 10;
    int d = 20;
    swap02(&c, &d);

    cout << "swap02 c = " << c << endl;
    cout << "swap02 d = " << d << endl;

    return 0;
}