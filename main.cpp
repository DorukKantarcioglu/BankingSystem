#include "Bank.h"
using namespace std;

int main()
{
    Bank b;
    b.admitPerson("Doruk", 78);
    b.admitPerson("Murat", 34);
    b.admitPerson("Sener Sen", 987);
    b.print();
    b.registerAccount(45);
    b.print();
    b.registerAccount(10);
    b.print();
    b.dismissPerson();
    b.print();
}
