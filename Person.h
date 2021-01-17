#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <string>

class Person
{
    public:
        Person(std::string = "", int = 0);
        friend std::ostream& operator <<(std::ostream&, const Person&);
        void operator =(const Person&);
        std::string getName() const;
        int getCurrency() const;
        void setCurrency(bool, int);
    private:
        std::string name;
        int currency;
};

#endif // PERSON_H_INCLUDED
