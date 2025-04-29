// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
using namespace std;

class LinkedList {
public:

    class Node {
    public:
        string data;
        Node* next;
        explicit Node(const string& val);
        ~Node();
    };
    using NodePtr = Node*;

private:
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
    void insertAfter(NodePtr prevNode, const string& data);
    void insertAtPosition(int position, const string& data);
    void swapNodes(NodePtr node1, NodePtr node2);

    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPosition(int position);
    void deleteByValue(char* value);

    const string& getDataAt(int index) const;
    int search(const string& value) const;

    void printList() const;
    void removeDuplicates();
    void makeCircular();
    bool isCircular() const;
    NodePtr getNodeAt(int index) const;

    // Node-based utilities (no STL)
    NodePtr createNode(int data);
    void appendNode(NodePtr& head, int data);
    NodePtr reverseList(NodePtr head);
    NodePtr reverseKGroup(NodePtr head, int k);
    NodePtr getPreviousNode(NodePtr head, NodePtr target);
    NodePtr getMiddleNode(NodePtr head);
    NodePtr getNthFromEnd(NodePtr head, int k);
    NodePtr getNthNode(NodePtr head, int n);
    NodePtr getHead(NodePtr head);
    NodePtr getTail(NodePtr head);
    void printList(NodePtr head);
    void freeList(NodePtr head);
    void reverseLinkedList();
};

#endif // LINKEDLIST_H