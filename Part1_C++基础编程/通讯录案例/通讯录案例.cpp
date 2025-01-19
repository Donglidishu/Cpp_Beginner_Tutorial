#include <iostream>
#include <string>
using namespace std;

#define MAX 100 // 最大人数

struct Person
{
    string m_Name;
    int m_Sex; // 1.男 2.女
    int m_Age;
    string m_Phone;
    string m_Addr;
};

// 通讯录结构体
struct Addressbook
{
    Person personArray[MAX]; // 通讯录中保存联系人的数组
    int m_Size;              // 通讯录人员个数
};

void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

void addPerson(Addressbook *abs) // 添加联系人函数
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满" << endl;
        return;
    }
    else
    {
        // 添加具体联系人

        // 姓名
        string nameIn;
        cout << "请输入姓名：" << endl;
        cin >> nameIn;
        abs->personArray[abs->m_Size].m_Name = nameIn;

        // 性别
        int sexIn = 0;
        cout << "请输入性别：" << endl;
        cout << "1--男  2--女" << endl;
        while (true)
        {
            cin >> sexIn;
            if (sexIn == 1 || sexIn == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sexIn;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入: " << endl;            // 输错之后重新输入
                cin.clear();                                         // 清除错误状态
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 这是清理无效输入行的常见方法，用于确保缓冲区没有残留字符
            }
        }

        // 年龄
        int ageIn = 0;
        cout << "请输入年龄：" << endl;
        cin >> ageIn;
        abs->personArray[abs->m_Size].m_Age = ageIn;

        // 电话
        string phoneIn;
        cout << "请输入电话号码：" << endl;
        cin >> phoneIn;
        abs->personArray[abs->m_Size].m_Phone = phoneIn;

        // 住址
        string addrIn;
        cout << "请输入地址：" << endl;
        cin >> addrIn;
        abs->personArray[abs->m_Size].m_Addr = addrIn;

        // 更新通讯录人数
        abs->m_Size++;

        cout << "添加成功" << endl;

        cout << "请按回车继续..." << endl;
        cin.get();
        cin.get();       // 确保捕获回车
        system("clear"); // 清屏 在windows中写作system(“cls")
    }
}

// 显示联系人
void showPerson(Addressbook *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前表内无联系人" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }

    cout << "请按回车继续..." << endl;
    cin.get();
    cin.get(); // 确保捕获回车
    system("clear");
}

// 判断联系人是否存在
int isExist(Addressbook *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i; // 遍历数组找到则返回该用户的数组位置编号
        }
    }
    return -1; // 未找到该名称的用户则返回-1
}

// 删除联系人
void deletePerson(Addressbook *abs)
{
    string name;
    cout << "请输入想要删除的联系人的姓名：" << endl;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1]; // 逐步覆盖以达到删除效果
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "未找到该联系人" << endl;
    }

    cout << "请按回车继续..." << endl;
    cin.get();
    cin.get(); // 确保捕获回车
    system("clear");
}

// 查找联系人
void findPerson(Addressbook *abs)
{
    string name;
    cout << "请输入要查找的联系人：" << endl;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    cout << "请按回车继续..." << endl;
    cin.get();
    cin.get(); // 确保捕获回车
    system("clear");
}

// 修改联系人
void modifyPerson(Addressbook *abs)
{
    string name;
    cout << "请输入要修改的联系人：" << endl;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        while (true)
        {
            cout << "该联系人当前信息为：" << endl;
            cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
            cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
            cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
            cout << "住址：" << abs->personArray[ret].m_Addr << endl;
            cout << endl;

            int select = 0;
            cout << "请输入需要修改的信息：" << endl;
            cout << "1--姓名  2--性别  3--年龄  4--电话  5--住址  0--退出" << endl;
            cin >> select;

            if (select == 1 || select == 2 || select == 3 || select == 4 || select == 5)
            {
                switch (select)
                {
                case 1: { // 修改姓名
                    cout << "请输入修改后的姓名，当前为：" << abs->personArray[ret].m_Name << endl;
                    cin >> name;
                    abs->personArray[ret].m_Name = name;
                    cout << "成功修改姓名为：" << abs->personArray[ret].m_Name << endl;
                }
                break;

                case 2: { // 修改性别
                    while (true)
                    {
                        int sexEdit = 0;
                        cout << "请输入修改后的性别(1--男 2--女)，当前为：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << endl;
                        cin >> sexEdit;
                        if (sexEdit == 1 || sexEdit == 2)
                        {
                            abs->personArray[ret].m_Sex = sexEdit;
                            cout << "成功修改性别为：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << endl;
                            break;
                        }
                        else
                        {
                            cout << "输入有误，请重新输入" << endl;
                        }
                    }
                }
                break;

                case 3: { // 修改年龄
                    cout << "请输入修改后的年龄，当前为：" << abs->personArray[ret].m_Age << endl;
                    cin >> abs->personArray[ret].m_Age;
                    cout << "成功修改年龄为：" << abs->personArray[ret].m_Age << endl;
                }
                break;

                case 4: { // 修改电话
                    cout << "请输入修改后的电话，当前为：" << abs->personArray[ret].m_Phone << endl;
                    cin >> abs->personArray[ret].m_Phone;
                    cout << "成功修改电话为：" << abs->personArray[ret].m_Phone << endl;
                }
                break;

                case 5: { // 修改住址
                    cout << "请输入修改后的住址，当前为：" << abs->personArray[ret].m_Addr << endl;
                    cin >> abs->personArray[ret].m_Addr;
                    cout << "成功修改住址为：" << abs->personArray[ret].m_Addr << endl;
                }
                break;
                }
            }
            else if (select == 0) // 退出修改
            {
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }
    }
    else // 未查找到该联系人
    {
        cout << "查无此人" << endl;
    }

    cout << "请按回车继续..." << endl;
    cin.get();
    cin.get(); // 确保捕获回车
    system("clear");
}

void cleanPerson(Addressbook *abs)
{
    char select;
    cout << "是否确认清空通讯录 y or n" << endl;
    cin >> select;

    while (true)
    {
        if (select == 'y')
        {
            abs->m_Size = 0;
            cout << "通讯录已清空" << endl;
            break;
        }
        else if (select == 'n')
        {
            break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
        }
    }

    cout << "请按回车继续..." << endl;
    cin.get();
    cin.get(); // 确保捕获回车
    system("clear");
}

int main()
{
    Addressbook abs; // 创建通讯录数组
    abs.m_Size = 0;  // 初始化数组大小，防止出现随机的垃圾值

    while (true)
    {
        showMenu(); // 展示菜单

        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:              // 1.添加联系人
            addPerson(&abs); // 利用地址传递可以修饰实参
            break;

        case 2: // 2.显示联系人
            showPerson(&abs);
            break;

        case 3: // 3.删除联系人
            deletePerson(&abs);
            break;

        case 4: // 4.查找联系人
            findPerson(&abs);
            break;

        case 5: // 5.修改联系人
            modifyPerson(&abs);
            break;

        case 6: // 6.清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 0.退出通讯录
            cout << "欢迎下次使用！" << endl;
            return 0;
        };
    }

    return 0;
}