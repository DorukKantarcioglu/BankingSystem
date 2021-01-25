/**
 * Implementation for the Person class.
 * Author: Doruk Kantarcýoðlu
 */
#include "Person.h"
using namespace std;

/// Parameterized constructor with default arguments
Person::Person(string personName, int personCurrency, int personAccountNo)
{
    name = personName;
    currency = personCurrency;
    accountNo = personAccountNo;
}

/// Operator overload
ostream& operator <<(ostream& os, const Person& person)
{
    os << "Name: " << person.getName() << '\t' << "Currency: " << person.getCurrency() << '\t';
    if (person.getAccountNo() > 0) {
        os << "Account number: " << person.getAccountNo();
    }
    else {
        os << "No registered account";
    }
    return os;
}

/// Operator overload
void Person::operator =(const Person& person)
{
    if (this != &person) {
        name = person.name;
        currency = person.currency;
        accountNo = person.accountNo;
    }
}

string Person::getName() const
{
    return name;
}

int Person::getCurrency() const
{
    return currency;
}

int Person::getAccountNo() const
{
    return accountNo;
}

void Person::setCurrency(bool withdrawing, int amount)
{
    if (withdrawing) {
        currency += amount;
    }
    else {
        currency -= amount;
    }
}

void Person::setAccountNo(int personAccountNo)
{
    accountNo = personAccountNo;
}
