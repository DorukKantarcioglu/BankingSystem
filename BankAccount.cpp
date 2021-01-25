/**
 * Implementation for the BankAccount class.
 * Author: Doruk Kantarcýoðlu
 */
#include "BankAccount.h"
using namespace std;

/// Default constructor
BankAccount::BankAccount()
{
    number = 0;
    name = "";
    balance = 0;
}

/// Parameterized constructor
BankAccount::BankAccount(int accountNo, string accountName, int accountBalance)
{
    number = accountNo;
    name = accountName;
    balance = accountBalance;
}

/// Operator overload
ostream& operator <<(ostream& os, const BankAccount& account)
{
    os << "Account number: " << account.getNumber() << '\t' << "Holder: " << account.getName() << '\t' << "Balance: " << account.getBalance();
    return os;
}

/// Operator overload
void BankAccount::operator =(const BankAccount& account)
{
    if (this != &account) {
        number = account.number;
        name = account.name;
        balance = account.balance;
    }
}

/// Operator overload
bool BankAccount::operator ==(const BankAccount& account) const
{
    return number == account.getNumber();
}

/// Operator overload
bool BankAccount::operator !=(const BankAccount& account) const
{
    return number != account.getNumber();
}

int BankAccount::getNumber() const
{
    return number;
}

string BankAccount::getName() const
{
    return name;
}

int BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::deposit(int amount)
{
    balance += amount;
}

void BankAccount::withdraw(int amount)
{
    balance -= amount;
}
