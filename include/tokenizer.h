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

        string popFront() {             // Remove and return the token at the front of the list
        if (isEmpty())              // If list is empty
            return string();        // Return empty string
        TokenNode* node = head;     // Create new node to remove
        string tok = node->token;   // Copy its token
        head = node->next;          // Advance head to next node
        if (!head)                  // If list is now empty
            tail = nullptr;         // Reset tail as well
        delete node;                // Delete the removed node
        return tok;                 // Return the token
    }

    void reverse() {                // Reverse the order of nodes in the list
        TokenNode* prev = nullptr;  // Previous node pointer (none at start)
        TokenNode* cur = head;      // Current node pointer starts at head
        tail = head;                // After reversal, original head becomes the tail
        while (cur) {               // Traverse through the list
            TokenNode* nxt = cur->next; // Store next node
            cur->next = prev;       // Reverse the link
            prev = cur;             // Move prev up
            cur = nxt;              // Move to next node
        }
        head = prev;                // After loop, prev is new head
    }
};

// tokenize: convert an expression string into a linked list of tokens
inline TokenList* tokenize(const string& expr) {
    TokenList* list = new TokenList(); // Create a new, empty TokenList
    size_t i = 0;                       // Index to traverse the expression string
    while (i < expr.size()) {          // Loop until end of string
        if (isspace(expr[i])) {        // Skip whitespace characters
            ++i;
            continue;
        }
        if (isdigit(expr[i]) || expr[i] == '.') {  // Number (integer or floating point)
            string num;
            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.'))
                num.push_back(expr[i++]); // Accumulate number characters
            list->append(num);         // Append the complete number token
        }
        else if (isalpha(expr[i])) {   // Identifier (variable/function name)
            string var;
            while (i < expr.size() && isalnum(expr[i]))
                var.push_back(expr[i++]); // Accumulate alphanumeric characters
            list->append(var);         // Append the complete identifier token
        }
        else {                         // Operator or parenthesis (any other single char)
            list->append(string(1, expr[i++])); // Append the single-character token
        }
    }
    return list;                       // Return the populated TokenList
}

#endif // TOKENIZER_H               // Include guard end

