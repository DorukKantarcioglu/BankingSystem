#include "LinkedList.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
    BankAccount acc1(35, "Doruk");
    cout << acc1 << endl;
    BankAccount acc2(47, "Karaman", 567);
    cout << acc2 << endl;
    cout << (acc1 == acc2) << endl;
    LinkedList LL;
    LL.insertToHead(acc1);
    LL.insertToTail(acc2);
    LL.display();
    LL.remove(acc1);
    LL.display();
    LL.remove(acc2);
    LL.display();

    acc1.deposit(5789);
    cout << acc1 << endl;
    acc1.withdraw(9876);
    cout << acc1 << endl;

    Person p1, p3;
    Person p2("Tay Keith", 3572);
    Queue q;
    q.enqueue(p2);
    q.getHead(p3);
    cout << p3 << endl;
    q.enqueue(p1);
    q.display();

}
