#include <iostream>
#include <string>
using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;
};

void bobbleSort(Hero heroArray[5], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (heroArray[j].age > heroArray[j + 1].age)
            {
                int temp = heroArray[j].age;
                heroArray[j].age = heroArray[j + 1].age;
                heroArray[j + 1].age = temp;
            }
        }
    }
}

void printInfo(Hero heroArray[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << heroArray[i].name << " " << heroArray[i].age << " " << heroArray[i].gender << endl;
    }
}

int main()
{
    Hero heroArray[5] =
        {
            {"刘备", 22, "男"},
            {"关羽", 21, "男"},
            {"张飞", 20, "男"},
            {"赵云", 23, "男"},
            {"貂蝉", 18, "女"}};

    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    
    bobbleSort(heroArray, len);
    printInfo(heroArray);

    return 0;
}
