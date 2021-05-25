/**
 * Implementation for the Bank class.
 * Includes the functions to be called in the driver file.
 * Author: DorukKantarcioglu
 */
#include "Bank.h"
using namespace std;

/// Default constructor
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
    cout << "New person " << name << " with currency " << currency << " has been admitted to the bank." << endl << endl;
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
            cout << "Account number " << accountNo << "does not belong to " << name << "." << endl << endl;
            return false;
        }
    }
    else {
        cout << "Process failed:" << endl;
        cout << "Account number " << accountNo << " does not exist." << endl << endl;
        return false;
    }
}

bool Bank::dismissPerson()
{
    if (numberOfPeople > 0) {
        people.dequeue();
        numberOfPeople--;
        cout << "Process successful:" << endl;
        cout << "Person " << people.getHeadName() << " with currency " << people.getHeadCurrency() << " has been dismissed from the bank." << endl << endl;
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
            cout << "Process successful:" << endl;
            cout << "Account number " << account.getNumber() << " has been terminated. Funds are handed to holder " << people.getHeadName() << "." << endl << endl;
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
                cout << "Process failed:" << endl;
                cout << "Deposit amount " << amount << " exceeds the currency " << people.getHeadCurrency() << " person " << people.getHeadName() << " has." << endl << endl;
                return false;
            }
            else {
                people.setHeadCurrency(false, amount);
                accounts.depositToAccount(people.getHeadAccountNo(), amount);
                cout << "Process successful:" << endl;
                cout <<  amount << " has been deposited to account number " << people.getHeadAccountNo() << "." << endl << endl;
                return true;
            }
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

bool Bank::withdraw(int amount)
{
    if (numberOfPeople > 0) {
        BankAccount account;
        if (accounts.getAccount(people.getHeadAccountNo(), account)) {
            if (account.getBalance() < amount) {
                cout << "Process failed:" << endl;
                cout << "Withdraw amount " << amount << " exceeds the balance " << account.getBalance() << " of account number " << account.getNumber() << "." << endl << endl;
                return false;
            }
            else {
                people.setHeadCurrency(true, amount);
                accounts.withdrawFromAccount(people.getHeadAccountNo(), amount);
                cout << "Process successful:" << endl;
                cout << amount << " has been withdrawn from account number " << account.getNumber() << "." << endl << endl;
                return true;
            }
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

bool Bank::transferToAccount(int accountNo, int amount)
{
    if (numberOfPeople > 0) {
        if (accounts.accountExists(accountNo)) {
            if (amount > people.getHeadCurrency()) {
                cout << "Process failed:" << endl;
                cout << "Transfer amount " << amount << " exceeds the currency " << people.getHeadCurrency() << " person " << people.getHeadName() << " has." << endl << endl;
                return false;
            }
            else {
                people.setHeadCurrency(false, amount);
                accounts.depositToAccount(accountNo, amount);
                cout << "Process successful:" << endl;
                cout << amount << " has been transfered to account number " << accountNo << "." << endl << endl;
                return true;
            }
        }
        else {
            cout << "Process failed:" << endl;
            cout << "Account number " << accountNo << " does not exist." << endl << endl;
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
    cout << "Number of registered bank accounts: " << numberOfAccounts << endl << endl;
    cout << "People information:" << endl;
    people.display();
    cout << "Account information:" << endl;
    accounts.display();
}

/// Displays the information of the person in front of the queue.
void Bank::printHead() const
{
    people.displayHead();
}
