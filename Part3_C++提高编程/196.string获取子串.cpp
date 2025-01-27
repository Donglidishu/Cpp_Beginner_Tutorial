#include <iostream>
#include <string>
using namespace std;

void test01()
{

    string str = "abcdefg";
    string subStr = str.substr(1, 3); // 从第1个位置开始往后查找3个
    cout << "subStr = " << subStr << endl;
}

// 实用用法: 查找用户名
void test02()
{
    string email = "donglidishu@github.com";
    int posAt = email.find("@");              // 查找@所在的位置索引
    string username = email.substr(0, posAt); // 从第0个位置查找到@所在索引的前一位
    cout << "username = " << username << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}