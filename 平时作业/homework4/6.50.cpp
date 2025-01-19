#include <iostream>
using namespace std;

void tripleByValue(int count)
{
    int triple = count * 3;
    cout << "count = " << triple << endl;
}

void tripleByReference(int &count)
{
    count *= 3;
    cout << "count = " << count << endl;
}

int main()
{
    int select;
    int count;
    cout << "请输入值: ";
    cin >> count;
    cout << "请选择1.值传递 2.引用传递: ";
    cin >> select;
    switch (select)
    {
    case 1:
        tripleByValue(count);
        break;
    case 2:
        tripleByReference(count);
        break;
    default:
        cout << "输入有误" << endl;
    }

    return 0;
}