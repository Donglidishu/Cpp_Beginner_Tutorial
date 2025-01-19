#include <iostream>
using namespace std;

struct Product
{
    int id;
    int sales;
    double price;
};

void func(int i, Product prd[])
{
    cout << "请输入产品销量";
    cin >> prd[i - 1].sales;
    
}

int main()
{
    int select;
    double total = 0.0;
    Product prd[5];
    double arg[5] = {2.98, 4.50, 9.98, 4.49, 6.78};
    for (int i = 0; i < 5; i++)
    {
        prd[i].id = i + 1;
        prd[i].sales = 0;
        prd[i].price = arg[i];
    }

    
    while (true)
    {
        select = 0;
        cout << "请输入产品编号(1-5) -1结束输入: ";
        cin >> select;
        if (select == -1)
        {
            for (int i = 0; i < 5; i++)
            {
                total += (prd[i].price * prd[i].sales);
            }
            cout << "总销售额为: " << total << endl;
            break;
        }
        else if (select > 0 && select < 6)
        {
            switch (select)
            {
            case 1:
                func(select, prd);
                break;
            case 2:
                func(select, prd);
                break;
            case 3:
                func(select, prd);
                break;
            case 4:
                func(select, prd);
                break;
            case 5:
                func(select, prd);
                break;

            default:
                break;
            }
        }
    }

    return 0;
}