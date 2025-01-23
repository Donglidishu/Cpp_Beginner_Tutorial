#pragma once
#include <iostream>
using namespace std;

template <class T>
class myArray
{
  public:
    // 有参构造
    myArray(int capacity)
    {
        // cout << "有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    // 拷贝构造
    myArray(const myArray &arr)
    {
        // cout << "拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress; 指针浅拷贝，会导致堆区数据重复释放

        this->pAddress = new T[arr.m_Capacity]; // 深拷贝

        // 将arr中的数据拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    myArray &operator=(const myArray &arr)
    {
        // cout << "operator=调用" << endl;
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != nullptr)
        {
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Size];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void pushBack(const T &val)
    {
        // 判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            cout << "容量已满" << endl;
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++; // 更新数组大小
    }

    // 尾删法
    void popBack()
    {
        if (this->m_Size == 0)
        {
            cout << "没有数据" << endl;
            return;
        }
        this->m_Size--; // 让用户访问不到最后一个元素，即为尾删，逻辑删除
    }

    // 通过下标的方式访问数组中的元素
    T &operator[](int index) // 函数调用还可以作为左值(可修改)所以使用引用
    {
        return this->pAddress[index];
    }

    // 返回数组的容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组的大小
    int getSize()
    {
        return this->m_Size;
    }

    ~myArray()
    {
        // cout << "析构调用" << endl;
        if (this->pAddress != nullptr)
        {
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
    }

  private:
    T *pAddress;    // 指针指向堆区开辟的真实的数组
    int m_Capacity; // 数组容量
    int m_Size;     // 数组大小
};