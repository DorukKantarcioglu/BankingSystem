#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include "Queue.h"
#include "LinkedList.h"

class Bank
{
    public:
        Bank();
        bool admitNewPerson(std::string, int);
        bool admitExistingPerson(std::string, int, int);
        bool dismissPerson();
        bool registerAccount(int = 0);
        bool terminateAccount();
        bool deposit(int);
        bool withdraw(int);
        bool transferToAccount(int, int);
        void print() const;
    private:
        int numberOfPeople, numberOfAccounts;
        Queue people;
        LinkedList accounts;
};

#endif // BANK_H_INCLUDED
