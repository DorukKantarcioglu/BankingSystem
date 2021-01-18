#include "Bank.h"
using namespace std;

Bank::Bank()
{
    numberOfPeople = 0;
    numberOfAccounts = 0;
}

bool Bank::admitNewPerson(string name, int currency)
{
    people.enqueue(Person(name, currency));
    numberOfPeople++;
    return true;
}

bool Bank::admitExistingPerson(string name, int currency, int accountNo)
{
    BankAccount account;
    if (accounts.getAccount(accountNo, account) && account.getName() == name) {
        people.enqueue(Person(name, currency, accountNo));
        numberOfPeople++;
        return true;
    }
    else {
        return false;
    }
}

bool Bank::dismissPerson()
{
    if (numberOfPeople > 0) {
        people.dequeue();
        numberOfPeople--;
        return true;
    }
    else {
        return false;
    }
}

bool Bank::registerAccount(int initialBalance)
{
    if (numberOfPeople > 0) {
        if (initialBalance > people.getHeadCurrency() || accounts.accountExists(people.getHeadAccountNo())) {
            return false;
        }
        else {
            people.setHeadCurrency(false, initialBalance);
            int availableNo = 1;
            while (accounts.accountExists(availableNo)) {
                availableNo++;
            }
            people.setHeadAccountNo(availableNo);
            accounts.insertToHead(BankAccount(availableNo, people.getHeadName(), initialBalance));
            numberOfAccounts++;
            return true;
        }
    }
    else {
        return false;
    }
}

bool Bank::terminateAccount()
{
    if (numberOfPeople > 0) {
        BankAccount account;
        if (accounts.getAccount(people.getHeadAccountNo(), account)) {
            accounts.remove(account);
            people.setHeadCurrency(true, account.getBalance());
            people.setHeadAccountNo(0);
            numberOfAccounts--;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Bank::deposit(int amount)
{
    if (numberOfPeople > 0) {
        if (accounts.accountExists(people.getHeadAccountNo())) {
            if (amount > people.getHeadCurrency()) {
                return false;
            }
            else {
                people.setHeadCurrency(false, amount);
                accounts.depositToAccount(people.getHeadAccountNo(), amount);
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Bank::withdraw(int amount)
{
    if (numberOfPeople > 0) {
        BankAccount account;
        if (accounts.getAccount(people.getHeadAccountNo(), account)) {
            if (account.getBalance() < amount) {
                return false;
            }
            else {
                people.setHeadCurrency(true, amount);
                accounts.withdrawFromAccount(people.getHeadAccountNo(), amount);
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Bank::transferToAccount(int accountNo, int amount)
{
    if (numberOfPeople > 0) {
        if (accounts.accountExists(accountNo)) {
            if (amount > people.getHeadCurrency()) {
                return false;
            }
            else {
                people.setHeadCurrency(false, amount);
                accounts.depositToAccount(accountNo, amount);
                return true;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void Bank::print() const
{
    cout << "Number of people in the bank: " << numberOfPeople << endl;
    cout << "Number of bank accounts: " << numberOfAccounts << endl;
    cout << "Account infos:" << endl;
    accounts.display();
    cout << endl;
    cout << "People info" << endl;
    people.display();
}
