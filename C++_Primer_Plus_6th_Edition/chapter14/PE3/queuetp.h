#ifndef QUEUETP_H_
#define QUEUETP_H_


template <class Item>
class Queue {
    private:
        // class scope definitions
        // Node is a nested structure definition local to this class
        struct Node { Item item; struct Node * next;};
        enum {Q_SIZE = 10};
        // private class members
        Node * front; // pointer to front of Queue
        Node * rear; // pointer to rear of Queue
        int items; // current number of items in Queue
        const int qsize; // maximum number of items in Queue
        // preemptive definitions to prevent public copying
        Queue(const Queue & q) : qsize(0) { }
        Queue & operator=(const Queue & q) { return *this;}
    public:
        Queue(int qs = Q_SIZE); // create queue with a qs limit
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item &item); // add item to end
        bool dequeue(Item &item); // remove item from front
};

#include <cstdlib> // (or stdlib.h) for rand()
// Queue methods

template <class Item>
Queue<Item>::Queue(int qs) : qsize(qs) {
    front = rear = NULL; // or nullptr
    items = 0;
}

template <class Item>
Queue<Item>::~Queue() {
    Node * temp;
    while (front != NULL) {// while queue is not yet empty
        temp = front; // save address of front item
        front = front->next;// reset pointer to next item
        delete temp; // delete former front
    }
}

template <class Item>
bool Queue<Item>::isempty() const {
    return items == 0;
}

template <class Item>
bool Queue<Item>::isfull() const {
    return items == qsize;
}

template <class Item>
int Queue<Item>::queuecount() const {
    return items;
}

template <class Item>
// Add item to queue
bool Queue<Item>::enqueue(const Item & item) {
    if (isfull())
        return false;
    Node * add = new Node; // create node
    // on failure, new throws std::bad_alloc exception
    add->item = item; // set node pointers
    add->next = NULL; // or nullptr;
    items++;
    if (front == NULL) // if queue is empty,
        front = add; // place item at front
    else
        rear->next = add; // else place at rear
    rear = add; // have rear point to new node
    return true;
}

template <class Item>
// Place front item into item variable and remove from queue
bool Queue<Item>::dequeue(Item & item) {
    if (front == NULL)
        return false;
    item = front->item; // set item to first item in queue
    items--;
    Node * temp = front; // save location of first item
    front = front->next; // reset front to next item
    delete temp; // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}
#endif