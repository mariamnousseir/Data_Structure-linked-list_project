// tokenizer.h
#ifndef TOKENIZER_H               // Include guard start: prevents multiple inclusions of this header
#define TOKENIZER_H

#include <string>                 // Include string library for std::string
#include <cctype>                 // Include cctype for character classification functions (isspace, isdigit, etc.)

using namespace std;

// Node for linked list of tokens
typedef struct TokenNode {
    string token;                 // The token text stored in this node
    TokenNode* next;              // Pointer to the next node in the list
    TokenNode(const string& t)    // Constructor: initialize token and set next to nullptr
        : token(t), next(nullptr) {
    }
} TokenNode;

// Linked list for tokens
class TokenList {
public:
    TokenNode* head;              // Pointer to the first node in the list
    TokenNode* tail;              // Pointer to the last node in the list

    TokenList()                    // Constructor: initialize head and tail to nullptr (empty list)
        : head(nullptr), tail(nullptr) {
    }

    ~TokenList() {                 // Destructor: delete all nodes to free memory
        TokenNode* cur = head;     // Start at the head
        while (cur) {              // Traverse until end of list
            TokenNode* nxt = cur->next; // Keep pointer to next node
            delete cur;            // Delete current node
            cur = nxt;             // Move to next node
        }
    }

    void append(const string& tok) {  // Append a new token to the end of the list
        TokenNode* node = new TokenNode(tok); // Create a new node with the token
        if (!head)                   // If list is empty
            head = tail = node;      // New node becomes both head and tail
        else {
            tail->next = node;       // Link current tail to new node
            tail = node;             // Update tail to new node
        }
    }

    bool isEmpty() const {          // Check if the list is empty
        return head == nullptr;     // True if head is null
    }
