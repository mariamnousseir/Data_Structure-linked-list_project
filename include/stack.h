#ifndef STACK_H                 // Include guard start: prevents multiple inclusions of this header
#define STACK_H

#include <stdexcept>            // Include the standard exception classes (for underflow_error)

using namespace std;            // Use the std namespace to avoid std:: prefix

// Stack implemented using a singly linked list
template <typename T>            // Make the Stack class a template to hold any data type T
class Stack {
private:
    struct Node {                // Internal node structure for linked list
        T data;                  // Data stored in this node
        Node* next;              // Pointer to the next node in the stack
        Node(const T& d, Node* n) : data(d), next(n) {}  // Node constructor initializes data and next pointer
    };
    Node* topNode;               // Pointer to the top node of the stack

public:
    Stack() : topNode(nullptr) {}// Constructor initializes topNode to nullptr (empty stack)
    ~Stack() {                   // Destructor cleans up all remaining nodes
        while (!isEmpty())       // Loop until the stack is empty
            pop();               // Pop each element, deleting its node
    }

    void push(const T& item) {   // Push a new item onto the stack
        topNode = new Node(item, topNode);  // Create a new node whose next is current top, then update topNode
    }

    T pop() {                    // Pop the top item off the stack and return its value
        if (isEmpty())           // If stack is empty, cannot pop
            throw underflow_error("Stack underflow");  // Throw an exception on underflow
        Node* node = topNode;    // Temporarily store pointer to top node
        T value = node->data;    // Copy the data to return
        topNode = node->next;    // Move topNode down to the next node
        delete node;             // Delete the old top node to free memory
        return value;            // Return the popped value
    }

    T peek() const {             // Return (but do not remove) the top item
        if (isEmpty())           // If stack is empty, cannot peek
            throw underflow_error("Stack is empty");  // Throw an exception if there is no element
        return topNode->data;    // Return the data from the top node
    }

    bool isEmpty() const {       // Check if the stack is empty
        return topNode == nullptr;  // True if topNode is null, false otherwise
    }
};

#endif // STACK_H             // Include guard end