#include <iostream>
using namespace std;

#define MAX 10

struct carInfo
{
    int num;
    double hours;
    double charges;
};
struct carArr
{
    carInfo arr[MAX];
    int m_size;
};

void caculateCharges(carArr *carBook, double hours)
{
    carBook->arr[carBook->m_size].hours = hours;
    carBook->arr[carBook->m_size].num = carBook->m_size + 1;
    if (hours <= 3)
    {
        carBook->arr[carBook->m_size].charges = 2;
    }
    else
    {
        if (hours < 19)
        {
            carBook->arr[carBook->m_size].charges = (((hours + 0.9) / 1) - 3) * 0.5 + 2;
        }
        else if (hours < 24)
        {
            carBook->arr[carBook->m_size].charges = 10;
        }
    }
}

void showInfo(carArr *carBook)
{
    cout << "Car\t" << "Hours\t" << "Charge\t" << endl;
    for (int i = 0; i < carBook->m_size; i++)
    {
        cout << carBook->arr[i].num << "\t"
             << carBook->arr[i].hours << "\t"
             << carBook->arr[i].charges << endl;
    }
}

int main()
{
    carArr carBook;
    double hours;
    carBook.m_size = 0;
    while (hours != -1)
    {
        cout << "请输入停车时长(-1退出): ";
        cin >> hours;
        if (hours == -1)
        {
            break;
        }
        caculateCharges(&carBook, hours);
        carBook.m_size++;
    }

    showInfo(&carBook);

    return 0;
}