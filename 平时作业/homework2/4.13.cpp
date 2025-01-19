#include <iostream>
using namespace std;
int main()
{
    float miles = 0;
    float gallons = 0;
    float t_miles = 0;
    float t_gallons = 0;

    while (true)
    {

        cout << "Enter miles driven(-1 to quit): ";
        cin >> miles;
        if (miles == -1)
        {
            break;
        }
        t_miles += miles;

        cout << "Enter gallons used: ";
        cin >> gallons;
        t_gallons += gallons;

        float MPG = miles / gallons;
        cout << "MPG this trip: " << MPG << endl;

        float t_MPG = t_miles / t_gallons;
        cout << "Total MPG: " << t_MPG << endl;

        cout << endl;
    }

    return 0;
}