#include "Bank.h"
using namespace std;

int main()
{
    Bank b;
    b.admitNewPerson("Doruk", 78);
    b.admitNewPerson("Tiesto", 34);
    b.admitNewPerson("Sener Sen", 987);
    b.print();
    b.registerAccount(45);
    b.print();
    b.registerAccount(10);
    b.print();
    b.dismissPerson();
    b.print();
    b.admitExistingPerson("Doruk", 768, 1);
    b.print();
    b.registerAccount(23);
    b.dismissPerson();
    b.dismissPerson();
    b.print();
    b.registerAccount();
    b.print();
    b.terminateAccount();
    b.print();
    b.registerAccount();
    b.print();
    cout << b.deposit(300) << endl;
    b.print();
    b.admitNewPerson("Kendrick Lamar", 3500);
    b.dismissPerson();
    b.print();
    b.registerAccount(3500);
    b.print();
    b.dismissPerson();
    b.admitExistingPerson("Tiesto", 7890, 2);
    b.print();
    b.deposit(7890);
    b.print();
    b.withdraw(4500);
    cout << "-----CHECKPOINT-----" << endl << endl;
    b.print();
    b.transferToAccount(1, 567);
    b.print();
//    b.terminateAccount();
//    b.print();
//    b.dismissPerson();
//    b.admitNewPerson("Jermaine Cole", 0);
//    b.print();
//    b.registerAccount();
//    b.print();
}
