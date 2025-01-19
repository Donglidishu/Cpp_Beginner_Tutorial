#include <fstream> //对文件操作需要包含fstream
#include <ios>
#include <iostream>
using namespace std;

void test01()
{
    // 1.包含头文件
    // 2.创建流对象
    ifstream ifs;

    // 3.打开文件并判断是否打开成功
    ifs.open("143.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }

    // 4.读数据
    // 第一种
    char buf[1024] = {0};
    while (ifs >> buf) // 逐行读文件，如果读不到了则为假，循环退出
    {
        cout << buf << endl;
    }

    // 5.关闭文件
    ifs.close();
}

int main()
{
    test01();
    return 0;
}