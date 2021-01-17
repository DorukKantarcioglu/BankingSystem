#include "Person.h"
using namespace std;

Person::Person(string personName, int personCurrency, int personAccountNo)
{
    name = personName;
    currency = personCurrency;
    accountNo = personAccountNo;
}

ostream& operator <<(ostream& os, const Person& person)
{
    os << "Name of individual: " << person.getName() << "\nCurrency: " << person.getCurrency();
    return os;
}

void Person::operator =(const Person& person)
{
    if (this != &person) {
        name = person.name;
        currency = person.currency;
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
