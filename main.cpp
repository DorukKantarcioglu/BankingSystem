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
    cout << endl << endl;
    acc1.deposit(5789);
    cout << acc1 << endl;
    cout << "--------------" << endl;
    cout << acc2 << endl;
    LL.insertToHead(acc1);
    LL.insertToTail(acc2);
    LL.display();
    LL.depositToAccount(47, 90000);
    LL.display();
    LL.withdrawFromAccount(47, 1234567);
    LL.display();
    if (LL.withdrawFromAccount(47, 123)) {
        cout << "cash money" << endl;
    }
    LL.display();
    LL.depositToAccount(35, 999999);
    LL.display();
    if (LL.withdrawFromAccount(35, 1005788))
        cout << "broke" << endl;

    LL.display();
    if (LL.withdrawFromAccount(35, 1005788))
        cout << "broke" << endl;
}
