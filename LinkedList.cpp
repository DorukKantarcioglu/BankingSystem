/**
 * Implementation for the LinkedList class.
 * Author: DorukKantarcioglu
 */
#include "LinkedList.h"
using namespace std;

/// Default constructor
LinkedList::LinkedList()
{
    head = NULL;
}

/// Copy constructor
LinkedList::LinkedList(const LinkedList& copy)
{
    if (copy.head == NULL) {
        head = NULL;
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
    }
}

/// Destructor
LinkedList::~LinkedList()
{
    Node* curr;
    while (head != NULL) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

bool LinkedList::isEmpty() const
{
    return head == NULL;
}

void LinkedList::insertToHead(LinkedListItem item)
{
    Node* newNode = new Node;
    newNode->data = item;
    if (isEmpty()) {
        newNode->next = NULL;
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::insertToTail(LinkedListItem item)
{
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void LinkedList::remove(LinkedListItem item)
{
    if (getNode(item) != NULL) {
        Node* curr = head;
        if (head->data == item) {
            head = head->next;
            delete curr;
        }
        else {
            while (curr->next != NULL && curr->next->data != item) {
                curr = curr->next;
            }
            Node* target = curr->next;
            if (target != NULL) {
                curr->next = target->next;
                delete target;
            }
        }
    }
}

void LinkedList::display() const
{
    if (isEmpty()) {
        cout << "There are no registered accounts." << endl << endl;
    }
    else {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << '\n';
            curr = curr->next;
        }
        cout << endl;
    }
}

bool LinkedList::accountExists(int accountNo) const
{
    for (Node* n = head; n != NULL; n = n->next) {
        if (n->data.getNumber() == accountNo) {
            return true;
        }
    }
    return false;
}

bool LinkedList::getAccount(int accountNo, BankAccount& account) const
{
    bool exists = false;
    for (Node* n = head; n != NULL; n = n->next) {
        if (n->data.getNumber() == accountNo) {
            exists = true;
            account = n->data;
            break;
        }
    }
    return exists;
}

bool LinkedList::depositToAccount(int accountNo, int amount)
{
    for (Node* n = head; n != NULL; n = n->next) {
        if (n->data.getNumber() == accountNo) {
            n->data.deposit(amount);
            return true;
        }
    }
    return false;
}

bool LinkedList::withdrawFromAccount(int accountNo, int amount)
{
    for (Node* n = head; n != NULL; n = n->next) {
        if (n->data.getNumber() == accountNo) {
            if (n->data.getBalance() - amount >= 0) {
                n->data.withdraw(amount);
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

/// Private function
LinkedList::Node* LinkedList::getNode(LinkedListItem item)
{
    if (isEmpty()) {
        return NULL;
    }
    else {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == item) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
}
