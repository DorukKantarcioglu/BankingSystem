#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "BankAccount.h"

typedef BankAccount LinkedListItem;
class LinkedList
{
    public:
        LinkedList();
        LinkedList(const LinkedList&);
        ~LinkedList();
        bool isEmpty() const;
        void insertToHead(LinkedListItem);
        void insertToTail(LinkedListItem);
        void remove(LinkedListItem);
        void display() const;
        // Methods to adjust inter/intra-account transactions:
        bool accountExists(int) const;
        bool getAccount(int AccountNo, BankAccount&) const;
        bool depositToAccount(int, int);
        bool withdrawFromAccount(int, int);
    private:
        struct Node {
            LinkedListItem data;
            Node* next;
        };
        Node* head;
        Node* getNode(LinkedListItem);
};

#endif // LINKEDLIST_H_INCLUDED
