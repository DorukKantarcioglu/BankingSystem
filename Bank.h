#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include "Queue.h"
#include "LinkedList.h"

class Bank
{
    public:
        Bank();
        bool admitPerson(std::string, int);
        bool dismissPerson();
        bool registerAccount(int);
        bool terminateAccount();
        void deposit(int);
        void withdraw(int);
        void transferToAccount(int, int);
        void print() const;
    private:
        int numberOfPeople, numberOfAccounts;
        Queue people;
        LinkedList accounts;
};

#endif // BANK_H_INCLUDED
