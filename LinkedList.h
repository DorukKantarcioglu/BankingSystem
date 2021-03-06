/**
 * Interface for the LinkedList class.
 * Author: DorukKantarcioglu
 */
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
        /// Application-specific functions
        bool accountExists(int) const;
        bool getAccount(int, BankAccount&) const;
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
