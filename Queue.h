/**
 * Interface for the Queue class.
 * Author: Doruk Kantarcýoðlu
 */
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "Person.h"

typedef Person QueueItemType;
class Queue
{
    public:
        Queue();
        Queue(const Queue&);
        ~Queue();
        bool isEmpty() const;
        bool getHead(QueueItemType&) const;
        void enqueue(QueueItemType);
        void dequeue();
        void display() const;
        void displayHead() const;
        /// Application-specific functions
        std::string getHeadName() const;
        int getHeadCurrency() const;
        int getHeadAccountNo() const;
        void setHeadCurrency(bool, int);
        void setHeadAccountNo(int);
    private:
        struct Node {
            QueueItemType data;
            Node* next;
        };
        Node* head;
        Node* tail;
};

#endif // QUEUE_H_INCLUDED
