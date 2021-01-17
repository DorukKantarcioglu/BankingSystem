#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED
#include <iostream>
#include <string>

class BankAccount
{
    public:
        BankAccount();
        BankAccount(int, std::string, int = 0);
        friend std::ostream& operator <<(std::ostream&, const BankAccount&);
        void operator =(const BankAccount&);
        bool operator ==(const BankAccount&) const;
        bool operator !=(const BankAccount&) const;
        int getNumber() const;
        std::string getName() const;
        int getBalance() const;
        void deposit(int);
        void withdraw(int);
    private:
        int number;
        std::string name;
        int balance;
};

#endif // BANKACCOUNT_H_INCLUDED
