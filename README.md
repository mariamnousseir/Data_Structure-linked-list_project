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







