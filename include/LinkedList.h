#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
using namespace std;

class LinkedList {
private:
    class Node {
    public:
        string data;
        Node* next;
        Node(const string& val);
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

    void insertAtFront(const string& data);
    void insertAtEnd(const string& data);
    void insertAfter(Node* prevNode,const string& data);
    void insertAtPosition(int position,const string& data);
    void swapNodes(Node*node1,Node*node2);

    const string& getDataAt(int index) const;
    int search(const string& value) const;

    void printList() const;
    void removeDuplicates();
    void makeCircular();

    using NodePtr = Node*;
    NodePtr getNodeAt(int index) const;
};

#endif // LINKEDLIST_H
