#include <iostream>
using namespace std;
int main()
{
    // 语法：for(起始表达式;条件表达式;末尾循环体){循环语句};

    // 输出0~9

    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    // for可以做拆分，例如写成以下这种(复杂)

    /*

    int i = 0;
    for(; ; )
    {
        if(i >= 10)
        {
            break;
        }
        cout << i << endl;
        i++;
    }

    */

    return 0;
}