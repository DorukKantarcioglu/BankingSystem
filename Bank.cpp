#include "Bank.h"
using namespace std;

Bank::Bank()
{
    numberOfPeople = 0;
    numberOfAccounts = 0;
}

bool Bank::admitPerson(string name, int currency)
{
    people.enqueue(Person(name, currency));
    numberOfPeople++;
    return true;
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
            people.setHeadAccountNo(numberOfAccounts + 1);
            accounts.insertToHead(BankAccount(numberOfAccounts + 1, people.getHeadName(), initialBalance));
            numberOfAccounts++;
            return true;
        }
    }
    else {
        return false;
    }
}

// Last checkpoint
bool Bank::terminateAccount()
{
    if (numberOfPeople > 0) {
        BankAccount acc;
        if (accounts.getAccount(people.getHeadAccountNo(), acc)) {
            accounts.remove(acc);
            people.setHeadCurrency(true, acc.getBalance());
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

void Bank::print() const
{
    cout << "Number of people in the bank: " << numberOfPeople << endl;
    cout << "Account infos:" << endl;
    accounts.display();
    cout << endl;
    cout << "People info" << endl;
    people.display();
}
