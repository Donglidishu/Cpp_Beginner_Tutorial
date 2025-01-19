#include <iostream>
using namespace std;
int main()
{
    int counter = 0;
    float number, largest = 0;

    while (counter < 10)
    {
        cout << "请输入销售量" << endl;
        cin >> number;

        if (number > largest)
        {
            largest = number;
        }

        counter ++;
    }
    cout << "销售量最多为" << largest << endl;
    return 0;
}