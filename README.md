# Data_Structure-linked-list_project
# Milestone 1: Implemintation of the data structure for the program 
A C++ Linked List Implementation for the Stack

# Author: Mariam Nousseir (ID: 900182741) did the following: 

create the Repository  and did Structure with all files.
then Clone the Repo to the Local Machine.
Added the Files to Git Tracking.
Committed the Changes and pushed to gethub.
include/LinkedList.h :header file containing the definition of the LinkedList class and its nested Node class.
src/linkedlist.cpp:file conatining the implementation of each function.
src/main.cpp ; file containing test cases for the functions. 

Functions I implemented:
Constructor & Destructor:
LinkedList()
~LinkedList()
Capacity & Status:
bool isEmpty() const
bool isFull() const
int getLength() const
Data Manipulation:
const std::string& getDataAt(int index) const
int search(const char* value) const
Utilities:
void printList() const
void removeDuplicates()
void makeCircular()

Test Cases & Expected Output:

Test 1: Check if the list is empty initially Expected Output:
Is list empty? Yes

Test 2: Inserting tokens at the end of the list Expected Output:
List after insertions: 5 + ( 3 * 3 )

Test 3: Getting the length of the list Expected Output:
Length of list: 7

Test 4: Retrieve data at index 3 Expected Output:
Data at index 3: 3

Test 5: Searching for the first occurrence of the token '+' Expected Output:
Token '+' found at index: 1

Test 6: Removing duplicate tokens Expected Output:
List after removing duplicates: 5 + ( 3 * )
Length after removing duplicates: 5

Test 7: Making the list circular Expected Output:
List after converting to circular: 5 + ( 3 * 3 )

Test 8: Check if the list is full Expected Output:
Is list full? No

Test 9: Retrieve data at an out-of-bounds index (index 100) Expected Output:
Correctly handled out of bounds request



# Author: Farah Ghorab (ID: 900231162) did the following: 

insertion functions for the data structure linked lists
insertatFront , insertatEnd , insertAfter , insertatPosition 

Swap nodes function 

Test for each function in the main

# Author: Raphael demian (ID: 900231263) did the following: 
Here are the names of the functions from your code:
helped in the header for the linkedlist
createNode
appendNode
reverseList
reverseKGroup
getPreviousNode
getMiddleNode
getNthFromEnd
getNthNode
getHead
getTail
printList
freeList
reverseLinkedList

these are the tests in the main

cout << "\nTest 14: Node-based operations\n";
    LinkedList::Node* h = nullptr;
    list.appendNode(h, 1);
    list.appendNode(h, 2);
    list.appendNode(h, 3);
    list.appendNode(h, 4);
    list.appendNode(h, 5);
    list.appendNode(h, 6);
    list.appendNode(h, 7);
    list.appendNode(h, 8);
    list.appendNode(h, 9);
    list.appendNode(h, 10);

    list.printList(h);

    cout << "Test 15: Reverse recursive\n";
    LinkedList::Node* rev = list.reverseList(h);
    list.printList(rev);

    cout << "Test 16: Reverse in groups of 2\n";
    LinkedList::Node* grp = list.reverseKGroup(rev, 2);
    list.printList(grp);

    cout << "Test 17: Previous of second node\n";
    auto prev = list.getPreviousNode(grp, grp->next);
    cout << (prev? prev->data : string("null")) << "\n";

    cout << "Test 18: Middle node\n";
    auto mid = list.getMiddleNode(grp);
    cout << (mid? mid->data : string("null")) << "\n";

    cout << "Test 19: 2nd from end\n";
    auto nthEnd = list.getNthFromEnd(grp, 2);
    cout << (nthEnd? nthEnd->data : string("null")) << "\n";

    cout << "Test 20: 1st index\n";
    auto nth = list.getNthNode(grp, 1);
    cout << (nth? nth->data : string("null")) << "\n";

    cout << "Test 21: Head & Tail\n";
    auto headNode = list.getHead(grp);
    auto tailNode = list.getTail(grp);
    cout << (headNode? headNode->data : string("null")) << ", " << (tailNode? tailNode->data : string("null")) << "\n";

    cout << "Test 22: Free list\n";
    list.freeList(grp);
    list.printList(grp);






# ************************************************************************
# Milestone 2: Implemintation of the Expression converter application
# ************************************************************************

# Author: Mariam Nousseir (ID: 900182741) did the following: 
I created the following new files:
include/stack.h — Header file for the custom stack implementation
include/tokenizer.h — Header file for the tokenizer logic
include/converter.h — Header file for the infix/postfix/prefix conversion logic
src/milestone2_main.cpp — The main application file for CLI interaction
These were added in a clear folder structure (include/ and src/) to keep the project modular and maintainable.
Added the Files to Git Tracking.
Committed the Changes and pushed to gethub.

converter.h Setup: 

I Added include guard (#ifndef … #endif) and included <string>, stack.h, tokenizer.h.

Operator Helpers:

precedence(op) returns 3 for ^, 2 for *//, 1 for +/-, else 0.

isOperator(t) checks for +, -, *, /, ^.

Infix → Postfix

infixToPostfix(tokens) uses the shunting-yard:

Operands → output,

( pushed, ) pops until matching (,

Operators pop higher/equal precedence (left-associative except ^), then push.

Infix → Prefix

infixToPrefix(tokens): reverse list & swap (/), call infixToPostfix(), then reverse result.

Postfix → Infix

postfixToInfix(tokens): push operands on a stack; on operator pop two, wrap as "(a op b)", push back; finally re-tokenize.

Full CLI Implementation

I Implemented the entire milestone2_main.cpp, including:

A printList() helper to display token lists.

A REPL loop to select notation (Infix/Postfix/Prefix), read expressions, invoke the two relevant conversion functions, handle errors with try/catch, and exit cleanly on choice 4.

Memory Safety

Every new TokenList() is paired with a delete.

Stack<string> instances auto-cleanup on scope exit.


# Author: Farah Ghorab (ID: 900231162) did the following: 

Converter.h file , did the function of conversion of prefix to infix by reversing tokens and using a stack 

Tokenizer.h file, did the functions ( popFront , reverse , tokenize) 

Methodology and conclusion for code report 




# Author: Raphael demian (ID: 900231263) did the following: 

l did these functions Stack,Convert postfix to prefix notation  and l tested them  for code report l did experiments and the anaysis part
