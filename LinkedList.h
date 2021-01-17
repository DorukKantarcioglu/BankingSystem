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
        void display() const;
        void insertToHead(LinkedListItem);
        void insertToTail(LinkedListItem);
        void remove(LinkedListItem);
        // Methods to adjust intra-account transactions:
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
