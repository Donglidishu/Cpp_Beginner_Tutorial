#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    cout << "请输入一个五位整数: " << endl;
    cin >> num;

    int a = num / 10000;
    int b = (num / 1000) % 10;
    int c = (num / 100) % 10;
    int d = (num / 10) % 10;
    int e = num % 10;

    int arr[] = {a,b,c,d,e};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}