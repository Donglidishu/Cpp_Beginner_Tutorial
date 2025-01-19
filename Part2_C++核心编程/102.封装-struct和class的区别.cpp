#include <iostream>
using namespace std;

// class和struct唯一的区别是默认访问权限不同
// struct默认权限为公共 class默认为私有
class c1
{
    int m_A; // 默认权限私有
};

struct c2
{
    int m_B; // 默认权限公共
};

int main()
{
    c1 c1;
    // c1.m_A;//成员 "c1::m_A" (已声明 所在行数:8) 不可访问C/C++(265)
    c2 c2;
    c2.m_B; // 正常访问
    return 0;
}
