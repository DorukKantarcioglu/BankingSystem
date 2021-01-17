#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::Queue(const Queue& copy)
{
    if (copy.head == NULL) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = new Node;
        head->data = copy.head->data;
        Node* curr = head;
        for (Node* orig = copy.head->next; orig != NULL; orig = orig->next) {
            curr->next = new Node;
            curr = curr->next;
            curr->data = orig->data;
        }
        curr->next = NULL;
        tail = curr;
    }
}

Queue::~Queue()
{
    Node* curr;
    while (head != NULL) {
        curr = head;
        head = head->next;
        delete curr;
    }
    tail = NULL;
}

bool Queue::isEmpty() const
{
    return head == NULL;
}

bool Queue::getHead(QueueItemType& item) const
{
    if (isEmpty()) {
        return false;
    }
    else {
        item = head->data;
        return true;
    }
}

void Queue::enqueue(QueueItemType item)
{
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
}

void Queue::dequeue()
{
    if (!isEmpty()) {
        Node* temp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
        }
        temp->next = NULL;
        delete temp;
    }
}

void Queue::display() const
{
    if (isEmpty()) {
        cout << "The queue is empty." << endl;
    }
    else {
        cout << "The queue items:" << endl;
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << '\n';
            curr = curr->next;
        }
        cout << endl;
    }
}

string Queue::getHeadName() const
{
    return head->data.getName();
}

int Queue::getHeadCurrency() const
{
    return head->data.getCurrency();
}

int Queue::getHeadAccountNo() const
{
    return head->data.getAccountNo();
}

void Queue::setHeadCurrency(bool withdrawing, int amount)
{
    head->data.setCurrency(withdrawing, amount);
}

void Queue::setHeadAccountNo(int personAccountNo)
{
    head->data.setAccountNo(personAccountNo);
}
