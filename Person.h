/**
 * Interface for the Person class.
 * Author: DorukKantarcioglu
 */
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <string>

class Person
{
    public:
        Person(std::string = "", int = 0, int = 0);
        friend std::ostream& operator <<(std::ostream&, const Person&);
        void operator =(const Person&);
        std::string getName() const;
        int getCurrency() const;
        int getAccountNo() const;
        void setCurrency(bool, int);
        void setAccountNo(int);

    private:
        std::string name;
        int currency;
        int accountNo;
};

#endif // PERSON_H_INCLUDED
