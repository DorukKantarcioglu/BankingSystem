/**
 * Interface for the BankingSystem class.
 * Author: DorukKantarcioglu
 */
#ifndef BANKINGSYSTEM_H_INCLUDED
#define BANKINGSYSTEM_H_INCLUDED
#include "Bank.h"

class BankingSystem
{
    public:
        void printOperations() const;
        void processOperations();

    private:
        Bank bank;
};

#endif // BANKINGSYSTEM_H_INCLUDED
