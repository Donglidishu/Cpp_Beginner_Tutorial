#include <iostream>
using namespace std;

int main()
{
    int accountNumber;
    double beginningBalance, totalCharges, totalCredits, creditLimit, newBalance;

    cout << "Enter account number (or -1 to quit): ";
    cin >> accountNumber;

    while (accountNumber != -1)
    {
        cout << "Enter beginning balance: ";
        cin >> beginningBalance;
        cout << "Enter total charges: ";
        cin >> totalCharges;
        cout << "Enter total credits: ";
        cin >> totalCredits;
        cout << "Enter credit limit: ";
        cin >> creditLimit;

        newBalance = beginningBalance + totalCharges - totalCredits;
        cout << "New balance is " << newBalance << endl;

        if (newBalance > creditLimit)
        {
            cout << "Account: " << accountNumber << endl;
            cout << "Credit limit: " << creditLimit << endl;
            cout << "Balance: " << newBalance << endl;
            cout << "Credit Limit Exceeded." << endl;
        }

        cout << "\nEnter account number (or -1 to quit): ";
        cin >> accountNumber;
    }

    return 0;
}