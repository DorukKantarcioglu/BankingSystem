#include "Person.h"
using namespace std;

Person::Person(string personName, int personCurrency)
{
    name = personName;
    currency = personCurrency;
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

void Person::setCurrency(bool withdrawing, int amount)
{
    if (withdrawing) {
        currency += amount;
    }
    else {
        currency -= amount;
    }
}
