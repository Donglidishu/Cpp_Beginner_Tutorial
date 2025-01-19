#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User
{
    string username;
    string password;
};

// 注册函数
void userRegister(vector<User> &users) // 此处应当使用引用传递
{
    User user;
    char choicee;
    do
    {
        cout << "请输入用户名:" << endl;
        cin >> user.username;
        cout << "******************************" << endl;

        string confirmPassword;

        bool passwordConfirmed = false;

        while (!passwordConfirmed)
        {
            cout << "请输入密码:" << endl;
            cin >> user.password;
            cout << "******************************" << endl;
            cout << "再次输入密码:" << endl;
            cin >> confirmPassword;
            cout << "******************************" << endl;

            if (user.password == confirmPassword)
            {
                passwordConfirmed = true;
            }
            else
            {
                cout << "两次输入的密码不一致" << endl;
                cout << "******************************" << endl;
            }
        }

        users.push_back(user);

        cout << "是否继续添加用户 y or n" << endl;
        cin >> choicee;
        cout << "******************************" << endl;
    } while (choicee == 'y');
}

// 登录函数
void userLogin(vector<User> &users)
{
    string nameEnter;
    string passwordEnter;
    string nameInVector;
    bool userFound = false;

    cout << "请输入用户名:" << endl;
    cin >> nameEnter;
    cout << "******************************" << endl;

    for (int i = 0; i < users.size(); i++)
    {
        if (nameEnter == users[i].username) // 判断用户名是否存在
        {
            userFound = true;
            cout << "请输入密码:" << endl;
            cin >> passwordEnter;
            cout << "******************************" << endl;

            // 判断密码是否正确
            if (passwordEnter == users[i].password)
            {
                cout << "欢迎使用" << endl;
                cout << "******************************" << endl;
            }
            else
            {
                cout << "密码错误" << endl;
                cout << "******************************" << endl;
            }
            return;
        }
    }
    if (!userFound)
    {
        cout << "用户不存在" << endl;
        cout << "******************************" << endl;
    }
}

int main()
{
    vector<User> users;
    while (true)
    {
        int choice;
        cout << "******************************" << endl;
        cout << "1.注册 2.登录" << endl;
        cout << "******************************" << endl;
        cout << "选择操作：";
        cin >> choice;
        cout << "******************************" << endl;

        if (choice == 1)
        {
            userRegister(users);
        }
        else if (choice == 2)
        {
            userLogin(users);
        }
        else
        {
            cout << "输入不合法" << endl;
            break;
        }
    }

    return 0;
}