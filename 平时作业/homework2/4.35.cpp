#include <iostream>
#include <string>

using namespace std;

unsigned int studentCounter{0};
double initialBalance{1000.0};

class Account
{
  public:
    Account(unsigned int accNumber, string fName, string lName, double bal)
        : accountNumber{accNumber}, firstName{fName}, lastName{lName}, balance{bal}
    {
    }

    unsigned int accountNumber;
    string firstName;
    string lastName;
    double balance;
};

Account myAccount{12345, "John", "Doe", 500.0};

int main()
{
    cout << "Student Counter: " << studentCounter << endl;
    cout << "Initial Balance: " << initialBalance << endl;
    cout << "Account Info: " << myAccount.accountNumber << ", " << myAccount.firstName << " " << myAccount.lastName << ", " << "Balance: " << myAccount.balance << endl;

    return 0;
}