#include <bitset>  // 用于二进制表示
#include <iomanip> // 为了使用 setw 和流操纵符
#include <iostream>

using namespace std;

int main()
{
    // 打印表头
    cout << setw(10) << "Decimal" << setw(15) << "Binary"
         << setw(10) << "Octal" << setw(10) << "Hexadecimal" << endl;
    cout << string(45, '-') << endl; // 分割线

    // 遍历 1 到 256 范围内的每个数字
    for (int i = 1; i <= 256; i++)
    {
        cout << setw(10) << dec << i              // 十进制
             << setw(15) << bitset<8>(i)          // 二进制 (8 位)
             << setw(10) << oct << i              // 八进制
             << setw(10) << hex << uppercase << i // 十六进制（大写）
             << endl;
    }

    return 0;
}