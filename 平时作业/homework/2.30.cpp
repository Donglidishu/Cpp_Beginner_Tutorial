#include <iostream>
using namespace std;
int main()
{
    float weight = 0;
    float height = 0;

    cout << "请输入身高（米）：" << endl;
    cin >> height;

    cout << "请输入体重（千克）：" << endl;
    cin >> weight;

    float BMI = weight / (height * height);

    if (BMI < 18.5)
    {
        cout << "underweight" << endl;
    }
    else if (BMI<25)
    {
        cout << "normal" << endl;
    }
    else if (BMI<30)
    {
        cout << "overweight" << endl;
    }
    else
    {
        cout << "obese" << endl;
    }    
    
    

    

    return 0;
}