#include "linkedlist.h"

LinkedList::Node::Node(const std::string& val)
    : data(val), next(nullptr)
{}

LinkedList::Node::~Node() = default;

LinkedList::LinkedList()
    : head(nullptr), length(0)
{}

LinkedList::~LinkedList() {
    if (head) {
        //break potential circular link
        Node* tail = head;
        while (tail->next && tail->next != head)
            tail = tail->next;
        if (tail->next == head)
            tail->next = nullptr;
    }
    //delete all nodes
    Node* cur = head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

bool LinkedList::isFull() const {
    Node* tmp = nullptr;
    try {
        tmp = new Node(std::string());
    } catch (...) {
        return true;
    }
    delete tmp;
    return false;
}

int LinkedList::getLength() const {
    return length;
}

void LinkedList::insertAtEnd(const std::string& data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next && cur->next != head)
            cur = cur->next;
        cur->next = newNode;
    }
    ++length;
}

const std::string& LinkedList::getDataAt(int index) const {
    static const std::string empty;
    if (index < 0 || index >= length) {
        std::cerr << "Error: index out of bounds\n";
        return empty;
    }
    Node* cur = head;
    for (int i = 0; i < index; ++i)
        cur = cur->next;
    return cur->data;
}

int LinkedList::search(const std::string& value) const {
    Node* cur = head;
    int idx = 0;
    while (cur && idx < length) {
        if (cur->data == value)
            return idx;
        cur = cur->next;
        ++idx;
    }
    return -1;
}

void LinkedList::printList() const {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return;
    }
    Node* cur = head;
    int count = 0;
    while (cur && count < length) {
        std::cout << cur->data << ' ';
        cur = cur->next;
        ++count;
    }
    std::cout << '\n';
}

void LinkedList::removeDuplicates() {
    if (isEmpty()) return;
    Node* cur = head;
    while (cur) {
        Node* runner = cur;
        while (runner->next && runner->next != head) {
            if (runner->next->data == cur->data) {
                Node* dup = runner->next;
                runner->next = dup->next;
                delete dup;
                --length;
            } else {
                runner = runner->next;
            }
        }
        cur = cur->next;
        if (cur == head) break;
    }
}

void LinkedList::makeCircular() {
    if (isEmpty()) {
        std::cerr << "Cannot make an empty list circular\n";
        return;
    }
    Node* cur = head;
    while (cur->next && cur->next != head)
        cur = cur->next;
    cur->next = head;
}
