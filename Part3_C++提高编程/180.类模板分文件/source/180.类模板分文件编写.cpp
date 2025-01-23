#include <iostream>
#include <string>
using namespace std;

// #include "person.cpp" //解决方式1，包含cpp源文件

// 解决方式2，将声明和实现写到一起，文件后缀名改为.hpp
#include "person.hpp"

int main()
{
    Person<string, int> p1("张三", 18);
    p1.showPerson();
    return 0;
}