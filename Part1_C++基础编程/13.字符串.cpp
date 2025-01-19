#include <iostream>
#include <string> //使用cpp风格字符串要加
using namespace std;
int main()
{
    // 1.C风格字符串
    /*注意事项 用法：char 字符串名[]
    等号后面要用双引号包含起来字符串*/
    char str[] = "helloworld c";
    cout << str << endl;

    // 2.cpp风格字符串
    /*需要使用string头文件名*/
    string str2 = "helloworld cpp";
    cout << str2 << endl;

    return 0;
}