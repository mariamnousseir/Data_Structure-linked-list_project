#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void LinkedList::push_front(int value) {
    Node* node = new Node{value, head};
    head = node;
    ++count;
}

bool LinkedList::remove(int value) {
    Node** pp = &head;
    while (*pp) {
        if ((*pp)->data == value) {
            Node* toDelete = *pp;
            *pp = toDelete->next;
            delete toDelete;
            --count;
            return true;
        }
        pp = &(*pp)->next;
    }
    return false;
}

bool LinkedList::contains(int value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

size_t LinkedList::size() const {
    return count;
}
