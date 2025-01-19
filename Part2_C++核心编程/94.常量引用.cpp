#include <iostream>
using namespace std;

// 打印数据函数
void showValue(const int &val)
{
    // val = 1000; //无法再修改
    cout << "val = " << val << endl;
}

int main()
{
    // 常量引用
    // 使用场景：用来修饰形参，防止误操作
    // int a = 10;

    // 加上const之后 编译器将代码修改 int temp = 10; const int &ref = temp;
    const int &ref = 10; // 引用必须引一块合法的内存
    // ref = 20;//加入const变成只读，不可以修改

    int a = 100;
    showValue(a);

    cout << "a = " << a << endl; // 函数中使用引用传递，更改形参val的时候实参a也发生改变，但函数使用const之后就不会改变参数

    return 0;
}