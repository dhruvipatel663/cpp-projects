#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;
class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string accHolder, int accNumber, double initialBalance)
    {
        accountHolder = accHolder;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    // Deposit Money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "₹" << amount << " deposited successfully!" << endl;
        }
        else
        {
            cout << "Invalid amount! Please try again" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully!" << endl;
        }
        else if (amount < 0)
        {
            cout << "Invalid amount! Please try again" << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    // Display account details
    void display()
    {
        cout << "\n\nAccount Holder Name: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance;
    }

    // Get account number
    int getAccountNumber()
    {
        return accountNumber;
    }
};
int main()
{
    vector<BankAccount> accounts;
    int choice;
    while (true)
    {
        system("Color DE");
        cout << "\n\n----------- WELCOME TO BANK MANAGEMENT SYSTEM -----------\n\n";

        cout << "1. Create account" << endl;
        cout << "2. View account information/balance amount" << endl;
        cout << "3. Deposit money" << endl;
        cout << "4. Withdraw money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            string name;
            int number;
            double money;
            cout << "\n\nEnter Account Holder's name: ";
            cin.ignore();
            // cin >> name;
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> number;
            cout << "Enter initial balance: ";
            cin >> money;
            accounts.push_back(BankAccount(name, number, money));
            cout << "\nAccount created successfully!" << endl;
        }
        else if (choice == 2)
        {
            int number;
            bool found = false;
            cout << "Enter Account Number: ";
            cin >> number;
            for (auto &acc : accounts)
            {
                if (acc.getAccountNumber() == number)
                {
                    found = true;
                    acc.display();
                    break;
                }
            }
            if (!found)
            {
                cout << "Account not found! Please try again" << endl;
            }
        }
        else if (choice == 3)
        {
            int number;
            bool found = false;
            cout << "Enter Account Number: ";
            cin >> number;
            for (auto &acc : accounts)
            {
                if (acc.getAccountNumber() == number)
                {
                    double money;
                    cout << "Enter amount: ";
                    cin >> money;
                    found = true;
                    acc.deposit(money);
                    break;
                }
            }
            if (!found)
            {
                cout << "Account not found! Please try again" << endl;
            }
        }
        else if (choice == 4)
        {
            int number;
            bool found = false;
            cout << "Enter Account Number: ";
            cin >> number;
            for (auto &acc : accounts)
            {
                if (acc.getAccountNumber() == number)
                {
                    double money;
                    cout << "Enter amount: ";
                    cin >> money;
                    found = true;
                    acc.withdraw(money);
                    break;
                }
            }
            if (!found)
            {
                cout << "Account not found! Please try again" << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "\nExiting the system. Thank you!" << endl;
            system("Color 07");
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
