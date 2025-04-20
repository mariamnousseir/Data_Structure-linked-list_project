#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    cout << "Beginning LinkedList Data Structure Tests:\n";

    LinkedList list;

    cout << "\nTest 1: Check if list is empty initially:\n";
    cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << "\n";

    cout << "\nTest 2: Inserting tokens at the end of the list:\n";
    list.insertAtEnd("5");
    list.insertAtEnd("+");
    list.insertAtEnd("(");
    list.insertAtEnd("3");
    list.insertAtEnd("*");
    list.insertAtEnd("3");
    list.insertAtEnd(")");
    cout << "List after insertions: ";
    list.printList();

    cout << "\nTest 3: Getting the length of the list:\n";
    cout << "Length of list: " << list.getLength() << "\n";

    cout << "\nTest 4: Retrieve data at index 3:\n";
    const string& dataAtIndex = list.getDataAt(3);
    cout << "Data at index 3: " << dataAtIndex << "\n";

    cout << "\nTest 5: Searching for the first occurrence of token '+':\n";
    int foundIndex = list.search("+");
    if (foundIndex != -1)
        cout << "Token '+' found at index: " << foundIndex << "\n";
    else
        cout << "Token '+' not found in the list.\n";

    cout << "\nTest 6: Removing duplicate tokens:\n";
    list.removeDuplicates();
    cout << "List after removing duplicates: ";
    list.printList();
    cout << "Length after removing duplicates: " << list.getLength() << "\n";

    cout << "\nTest 7: Making the list circular:\n";
    list.makeCircular();
    cout << "List after converting to circular: ";
    list.printList();

    cout << "\nTest 8: Check if list is full:\n";
    cout << "Is list full? " << (list.isFull() ? "Yes" : "No") << "\n";

    cout << "\nTest 9: Retrieve data at an out of bounds index (index 100):\n";
    const string& invalidData = list.getDataAt(100);
    cout << "Correctly handled out of bounds request\n";

    cout << "\nTest 10: Inserting tokens at the start of the list:\n";
    list.insertAtFront("4");
    list.insertAtFront("+");
    list.insertAtFront("(");
    list.insertAtFront("2");
    list.insertAtFront("*");
    list.insertAtFront("3");
    list.insertAtFront("+");
    list.insertAtFront("5");
    list.insertAtFront("-");
    list.insertAtFront("7");
    list.insertAtFront(")");
    cout << "List after insertions: ";
    list.printList();

    cout << "Length of list after insertions: " << list.getLength() << endl;

    cout << "\nTest 11: Inserting node with value (3) after node containing value (2):" << endl;

    LinkedList::NodePtr node1 = list.getNodeAt(2); //to get node at index 2
    LinkedList::NodePtr node2 = list.getNodeAt(3); //to get node at index 3

    list.insertAfter(node1, "3"); //insert value 3 (node with name node2) after node containing the value 2 (node1)
    cout << "List after insertions: ";
    list.printList();

    cout << "\nTest 12: Inserting node at position 2:" << endl;
    list.insertAtPosition(2,"A"); //insert the data (A) at position 2
    cout << "List after insertions: ";
    list.printList();

    cout << "\nTest 13: swapping node1 with node2:" << endl;
    list.swapNodes(node1, node2);
    cout << "List after swapping nodes: ";
    list.printList();


    cout << "\nAll Tests Completed\n";
    return 0;
}
