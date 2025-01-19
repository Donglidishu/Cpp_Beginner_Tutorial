#include <iostream>
using namespace std;

int test01(int binary)
{
    int decimal = 0;
    int base = 1;

    while (binary > 0)
    {
        int lastDigit = binary % 10;
        decimal += lastDigit * base; 
        base *= 2;                  
        binary /= 10;                
    }

    return decimal;
}

int main()
{
    int binary;
    cout << "请输入二进制数: ";
    cin >> binary;

    int decimal = test01(binary);
    cout << "对应的十进制数是: " << decimal << endl;

    return 0;
}