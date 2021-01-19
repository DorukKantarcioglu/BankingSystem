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
    cout << "Process successful:" << endl;
    cout << "New person " << name << " with currency " << currency << " has been admitted to the bank." << endl;
    return true;
}

bool Bank::admitExistingPerson(string name, int currency, int accountNo)
{
    BankAccount account;
    if (accounts.getAccount(accountNo, account)) {
        if (account.getName() == name) {
            people.enqueue(Person(name, currency, accountNo));
            numberOfPeople++;
            cout << "Process successful:" << endl;
            cout << "Existing person " << name << " with currency " << currency << " and account number " << accountNo <<" has been admitted to the bank." << endl << endl;
            return true;
        }
        else {
            cout << "Process failed:" << endl;
            cout << "Account with number " << accountNo << "does not belong to " << name << "." << endl << endl;
            return false;
        }
    }
    else {
        cout << "Process failed:" << endl;
        cout << "Account with number " << accountNo << " does not exist." << endl << endl;
        return false;
    }
}

bool Bank::dismissPerson()
{
    if (numberOfPeople > 0) {
        string name = people.getHeadName();
        int currency = people.getHeadCurrency();
        people.dequeue();
        numberOfPeople--;
        cout << "Process successful:" << endl;
        cout << "Person " << name << " with currency " << currency << " has been dismissed from the bank." << endl << endl;
        return true;
    }
    else {
        cout << "Process failed:" << endl;
        cout << "The bank queue is empty." << endl << endl;
        return false;
    }
}

bool Bank::registerAccount(int initialBalance)
{
    if (numberOfPeople > 0) {
        if (accounts.accountExists(people.getHeadAccountNo())) {
            cout << "Process failed:" << endl;
            cout << "Person " << people.getHeadName() << " has another account with number " << people.getHeadAccountNo() << "." << endl << endl;
            return false;
        }
        else if (initialBalance > people.getHeadCurrency()){
            cout << "Process failed:" << endl;
            cout << "Initial balance " << initialBalance << " exceeds the currency " << people.getHeadCurrency() << " person " << people.getHeadName() << " has." << endl << endl;
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
            cout << "Process successful:" << endl;
            cout << "Account with number " << availableNo << " and initial balance " << initialBalance << " has been registered to person " << people.getHeadName() << "." << endl << endl;
            return true;
        }
    }
    else {
        cout << "Process failed:" << endl;
        cout << "The bank queue is empty." << endl << endl;
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
            cout << "Process failed:" << endl;
            cout << "Person " << people.getHeadName() << " does not have a registered account." << endl << endl;
            return false;
        }
    }
    else {
        cout << "Process failed:" << endl;
        cout << "The bank queue is empty." << endl << endl;
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
        cout << "Process failed:" << endl;
        cout << "The bank queue is empty." << endl << endl;
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
        cout << "Process failed:" << endl;
        cout << "The bank queue is empty." << endl << endl;
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
        cout << "Process failed:" << endl;
        cout << "The bank queue is empty." << endl << endl;
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
