#include "myArray.hpp"
#include <iostream>

using namespace std;

void printIntArray(myArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    myArray<int> arr1(5);
    for (int i = 0; i < 5; i++)
    {
        arr1.pushBack(i); // 利用尾插法向数组中插入数据
    }
    cout << "arr1打印输出" << endl;
    printIntArray(arr1);

    cout << "arr1容量为: " << arr1.getCapacity() << endl;
    cout << "arr1大小为: " << arr1.getSize() << endl;

    myArray<int> arr2(arr1);

    // 尾删
    arr2.popBack();
    cout << "arr2尾删后: " << endl;
    printIntArray(arr2);
    cout << "arr2容量为: " << arr2.getCapacity() << endl;
    cout << "arr2大小为: " << arr2.getSize() << endl;

    // myArray<int> arr2(arr1);
    // myArray<int> arr3(300);
    // arr3 = arr1;
}

// 测试自定义数据类型
class Person
{
  public:
    Person()
    {
    }
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

  public:
    string m_Name;
    int m_Age;
};

void printPersonArray(myArray<Person> &personArr)
{
    for (int i = 0; i < personArr.getSize(); i++)
    {
        cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
    }
}

void test02()
{
    myArray<Person> arr(10);

    Person p1("孙悟空", 30);
    Person p2("韩信", 20);
    Person p3("妲己", 18);
    Person p4("王昭君", 15);
    Person p5("赵云", 24);

    // 插入数据
    arr.pushBack(p1);
    arr.pushBack(p2);
    arr.pushBack(p3);
    arr.pushBack(p4);
    arr.pushBack(p5);

    printPersonArray(arr);
    cout << "pArray的大小: " << arr.getSize() << endl;
    cout << "pArray的容量: " << arr.getCapacity() << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}