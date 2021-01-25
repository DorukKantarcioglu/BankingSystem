/**
 * Driver file for the banking system.
 * Includes the main function in which it presents the user with operation codes.
 * Operation code 0 will termiante the process.
 * Author: Doruk Kantarcýoðlu
 */
#include "Bank.h"
using namespace std;

int main()
{
    Bank bank;
    cout << "Welcome user! This is a banking system application in which you can perform several operations:" << endl << endl;
    cout << "Operation code 1: Admit a new person to the end of the bank queue." << endl;
    cout << "Operation code 2: Admit an existing person with an account to the end of the bank queue." << endl;
    cout << "Operation code 3: Dismiss the person in front of the bank queue." << endl;
    cout << "Operation code 4: Register an account for the person in front of the bank queue." << endl;
    cout << "Operation code 5: Terminate the account of the person in front of the bank queue." << endl;
    cout << "Operation code 6: Deposit money to the account of the person in front of the bank queue." << endl;
    cout << "Operation code 7: Withdraw money from the account of the person in front of the bank queue." << endl;
    cout << "Operation code 8: Transfer currency from the person in front of the bank queue to another account." << endl;
    cout << "Operation code 9: Display information about the people in the bank and registered accounts." << endl;
    cout << "Operation code 0: Terminate the banking system application." << endl << endl;

    int code = -1;
    while (code != 0) {
        bank.printHead();
        cout << "Please enter the operation code for the corresponding request: ";
        cin >> code;
        switch (code) {
            case 1: {
                string name;
                int currency;
                cout << "Please enter the name and the currency of the new person accordingly:" << endl;
                cin >> name >> currency;
                bank.admitNewPerson(name, currency);
                cout << endl;
                break;
            }
            case 2: {
                string name;
                int currency, accountNo;
                cout << "Please enter the name, currency and the account number for the existing person accordingly:" << endl;
                cin >> name >> currency >> accountNo;
                bank.admitExistingPerson(name, currency, accountNo);
                cout << endl;
                break;
            }
            case 3: {
                bank.dismissPerson();
                cout << endl;
                break;
            }
            case 4: {
                int initialBalance;
                cout << "Please enter the initial balance of the account:" << endl;
                cin >> initialBalance;
                bank.registerAccount(initialBalance);
                cout << endl;
                break;
            }
            case 5: {
                bank.terminateAccount();
                cout << endl;
                break;
            }
            case 6: {
                int amount;
                cout << "Please enter the amount to be deposited to the account:" << endl;
                cin >> amount;
                bank.deposit(amount);
                cout << endl;
                break;
            }
            case 7: {
                int amount;
                cout << "Please enter the amount to be withdrawn from the account:" << endl;
                cin >> amount;
                bank.withdraw(amount);
                cout << endl;
                break;
            }
            case 8: {
                int accountNo, currency;
                cout << "Please enter the account number and the transfer amount accordingly:" << endl;
                cin >> accountNo >> currency;
                bank.transferToAccount(accountNo, currency);
                cout << endl;
                break;
            }
            case 9: {
                bank.print();
                cout << endl;
                break;
            }
            case 0: {
                cout << "Application terminated. Have a nice day!" << endl << endl;
                break;
            }
            default:
                cout << "Invalid input. Please enter one of the operation codes listed above." << endl;
        }
    }
}
