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
    private:
        struct Node {
            QueueItemType data;
            Node* next;
        };
        Node* head;
        Node* tail;
};

#endif // QUEUE_H_INCLUDED
