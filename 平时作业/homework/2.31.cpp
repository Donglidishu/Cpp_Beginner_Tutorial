#include <iostream>
using namespace std;
int main()
{
    float miles_pd = 0;
    float dollars_pg = 0;
    float avg_miles_pg = 0;
    float parking_exp = 0;
    float travel_exp = 0;
    int total = 0;

    cout << "请输入每天开的总英里数:" << endl;
    cin >> miles_pd;
    cout << "请输入每加仑汽油的价格:" << endl;
    cin >> dollars_pg;
    cout << "请输入每加仑汽油可以开的平均英里数:" << endl;
    cin >> avg_miles_pg;
    cout << "请输入每日的停车费:" << endl;
    cin >> parking_exp;
    cout << "请输入每日的通行费:" << endl;
    cin >> travel_exp;
    cout << "请输入共行人数:" << endl;
    cin >> total;

    float exp_avg = ((miles_pd / avg_miles_pg) * dollars_pg + parking_exp + travel_exp) / total;
    float single_avg = (miles_pd / avg_miles_pg) * dollars_pg + parking_exp + travel_exp;
    cout << total << "人同行每天的交通费为: " << exp_avg << endl;
    cout << "相比单人出行每天节省" << single_avg - exp_avg << endl;
    
    return 0;
}