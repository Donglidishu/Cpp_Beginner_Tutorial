#include <iostream>
using namespace std;

// 1.查找
void test01()
{
    string str = "abcdefgde";
    int pos = str.find("de"); // 存在的话返回第一个字母的位置，没有返回-1
    if (pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }

    // rfind
    pos = str.rfind("de");
    cout << "pos = " << pos << endl;

    // rfind 和 find的区别
    // rfind查找字符串最后一次出现的位置 find查找第一次出现的位置
}

// 2.替换
void test02()
{
    string str = "abcdefg";

    // 从1号位置起 替换3个字符为"1111"
    str.replace(1, 3, "1111");
    cout << "str = " << str << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}