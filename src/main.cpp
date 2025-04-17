#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;
    std::cout << "Initial size: " << list.size() << "\n";

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    std::cout << "After pushes (expect 3): " << list.size() << "\n";

    std::cout << "Contains 20? "
              << (list.contains(20) ? "yes" : "no") << "\n";

    std::cout << "Removing 20: "
              << (list.remove(20) ? "removed" : "not found") << "\n";

    std::cout << "Contains 20 now? "
              << (list.contains(20) ? "yes" : "no") << "\n";

    std::cout << "Final size (expect 2): " << list.size() << "\n";
    return 0;
}
