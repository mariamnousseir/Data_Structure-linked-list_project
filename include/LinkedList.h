#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void push_front(int value);
    bool remove(int value);
    bool contains(int value) const;
    size_t size() const;

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    size_t count;
};

#endif // LINKEDLIST_H
