#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

class LinkedList {
private:
    class Node {
    public:
        std::string data;
        Node* next;
        Node(const std::string& val);
        ~Node();
    };

    Node* head;
    int length;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    bool isFull() const;
    int getLength() const;

    void insertAtEnd(const std::string& data);
    const std::string& getDataAt(int index) const;
    int search(const std::string& value) const;

    void printList() const;
    void removeDuplicates();
    void makeCircular();
};

#endif // LINKEDLIST_H
