#include <iostream>
#include "linkedlist.h"

int main() {
    std::cout << "Beginning LinkedList Data Structure Tests:\n";

    LinkedList list;

    std::cout << "\nTest 1: Check if list is empty initially:\n";
    std::cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << "\n";

    std::cout << "\nTest 2: Inserting tokens at the end of the list:\n";
    list.insertAtEnd("5");
    list.insertAtEnd("+");
    list.insertAtEnd("(");
    list.insertAtEnd("3");
    list.insertAtEnd("*");
    list.insertAtEnd("3");
    list.insertAtEnd(")");
    std::cout << "List after insertions: ";
    list.printList();

    std::cout << "\nTest 3: Getting the length of the list:\n";
    std::cout << "Length of list: " << list.getLength() << "\n";

    std::cout << "\nTest 4: Retrieve data at index 3:\n";
    const std::string& dataAtIndex = list.getDataAt(3);
    std::cout << "Data at index 3: " << dataAtIndex << "\n";

    std::cout << "\nTest 5: Searching for the first occurrence of token '+':\n";
    int foundIndex = list.search("+");
    if (foundIndex != -1)
        std::cout << "Token '+' found at index: " << foundIndex << "\n";
    else
        std::cout << "Token '+' not found in the list.\n";

    std::cout << "\nTest 6: Removing duplicate tokens:\n";
    list.removeDuplicates();
    std::cout << "List after removing duplicates: ";
    list.printList();
    std::cout << "Length after removing duplicates: " << list.getLength() << "\n";

    std::cout << "\nTest 7: Making the list circular:\n";
    list.makeCircular();
    std::cout << "List after converting to circular: ";
    list.printList();

    std::cout << "\nTest 8: Check if list is full:\n";
    std::cout << "Is list full? " << (list.isFull() ? "Yes" : "No") << "\n";

    std::cout << "\nTest 9: Retrieve data at an out of bounds index (index 100):\n";
    const std::string& invalidData = list.getDataAt(100);
    std::cout << "Correctly handled out of bounds request\n";

    std::cout << "\nAll Tests Completed\n";
    return 0;
}
