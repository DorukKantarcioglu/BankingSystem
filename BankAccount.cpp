#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount()
{
    number = 0;
    name = "";
    balance = 0;
}

BankAccount::BankAccount(int accountNo, string accountName, int accountBalance)
{
    number = accountNo;
    name = accountName;
    balance = accountBalance;
}

ostream& operator <<(ostream& os, const BankAccount& account)
{
    os << "Account number: " << account.getNumber() << "\nAccount holder: " << account.getName() << "\nAccount balance: " << account.getBalance();
    return os;
}

void BankAccount::operator =(const BankAccount& account)
{
    if (this != &account) {
        number = account.number;
        name = account.name;
        balance = account.balance;
    }
}

bool BankAccount::operator ==(const BankAccount& account) const
{
    return number == account.getNumber();
}

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
