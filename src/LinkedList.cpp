#include "LinkedList.h"
#include <string>

LinkedList::Node::Node(const string& val)
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
        tmp = new Node(string());
    } catch (...) {
        return true;
    }
    delete tmp;
    return false;
}

int LinkedList::getLength() const {
    return length;
}


const string& LinkedList::getDataAt(int index) const {
    static const string empty;
    if (index < 0 || index >= length) {
        cerr << "Error: index out of bounds\n";
        return empty;
    }
    Node* cur = head;
    for (int i = 0; i < index; ++i)
        cur = cur->next;
    return cur->data;
}

int LinkedList::search(const string& value) const {
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
        cout << "List is empty\n";
        return;
    }
    Node* cur = head;
    int count = 0;
    while (cur && count < length) {
        cout << cur->data << ' ';
        cur = cur->next;
        ++count;
    }
    cout << '\n';
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

//function to check if list is circular
bool LinkedList::isCircular() const {
    if (isEmpty())
    {
        return false;
    }
    Node *current = head->next;
    if (current == head) {
        return true;
    }
    while(current!=nullptr)
    {
        if (current ==head){
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::insertAtFront(const string &data) {
    Node* newNode = new Node(data); // new node creation
    if (isEmpty()) //check if list is empty
    {
        head = newNode; //only one node which is the head
    }
    else
    {
        newNode->next = head; //new node points to head
        head = newNode; //update head to become the new node
    }
    ++length;  //increase list size
}


void LinkedList::insertAtEnd(const string& data) {
    Node* newNode = new Node(data); //creation of new node
    if (isEmpty()) //check if list is empty
    {
        head = newNode; //only one node
    }
    else
    {
        Node* cur = head; //create pointer current to start from head
        while (cur->next != nullptr && cur->next != head)//traverse through the list till last node
        {
            cur = cur->next; //to traverse through the list
        }
        cur->next = newNode; //insert new node at end
    }
    ++length; //increase list size
}

void LinkedList::insertAfter(Node *prevNode, const string &data) {
   if (prevNode == nullptr) //checks if there is a previous node or not
   {
       cerr << "error: previous node is null" << endl;
       return; //cannot insert after null
   }
    Node* newNode = new Node(data); //create a new node
    newNode->next = prevNode->next; //new node points to next of previous node
    prevNode->next = newNode; //to link the previous node to the new node

    ++length; //increase list size
}

void LinkedList::insertAtPosition(int position, const string &data) {
      if (position < 0 || position > length) //position not found
      {
          cerr << "error: position out of bounds" << endl;
          return; //cannot insert at that position
      }
     if (position == 0) //if position is the first node(head)
     {
         insertAtFront(data);
         return;
     }
    if (position == length) //if position is the last node(tail)
    {
        insertAtEnd(data);
        return;
    }
    //if position is in between the list
    Node* cur = head; //create a pointer to start from head
    for (int i = 0; i < position - 1; i++) //traverse through the list until we reach the node before desired position
    {
        cur = cur->next;
    }
    //when desired position is reached
    Node* newNode = new Node(data); //create new node
    newNode->next = cur->next; //next of new node points to position
    cur->next = newNode; //new node inserted at desired position

    ++length;
}

//deleting first node (head)
void LinkedList::deleteAtHead(){
  if (isEmpty()){ //checking if list is empty
    cerr << "error: list is empty,nothing to delete" << endl;
    }
    Node* current = head; //create a pointer that points to the head
    head = head->next; //update the head to be the second node (the next of the previous head)
    delete current; //delete current (which was the previous head)
    length--; //modify the length by decreasing
  }

  //deleting last node (tail)
  void LinkedList::deleteAtTail(){
    if (isEmpty()){ //check if list is empty
      cerr << "error: list is empty,nothing to delete" << endl;
    }
    if (head->next == nullptr){ //check if the list had only one node
      delete head; //delete the only node in the list (head)
      head = nullptr; // modify the list to be empty
      length--; //modify the length by decreasing
    }
    Node* current = head; //create a pointer (current) that points to the head
    while (current->next != nullptr) //traverse through the list until current is standing at last node
    {
      current = current->next;
    }
    delete current; //to delete last node
    current = nullptr; //last node deleted
    length--;
    }

    //deleting at a specific position
    void LinkedList::deleteAtPosition(int position){
    if(isEmpty()){ //check if list is empty
      cerr << "error: list is empty,nothing to delete" << endl;
      return;
    }
    if(position < 0 || position > length){ //check if position is less or more than the current length of the list
      cerr << "error: position out of bounds" << endl;
      return;
    }
    if (position == 0){ //check if desired position is the head
      deleteAtHead(); //reuse the delete at head function
      return;
      length--; //modify the length by decreasing
    }
    if (position == length){ //check if desired position is the tail
      deleteAtTail(); //reuse the delete at tail function
      return;
      length--; //modify the length by decreasing
    }
    //in case the required position is the middle of the list
    Node*current = head; //create a pointer (current) pointing to the head
    //a loop to traverse through the list till we reach the node preceeding the desired position
    for (int i = 0; i < position - 1; i++){
      current = current->next;
      }
    Node* previous = current; //create a pointer that points to the node preceeding the required position
    previous = current->next->next; //let the pointer before the node that requires deletion point to the node following the one required deletion (pointers modification)
    delete current->next; //delete node at desired position

    length--; //modify the length by decreasing
    }
    //deleting a node by desired value
    void LinkedList::deleteByValue(char* value){
      if(isEmpty()){ //check if list is empty
        cerr << "error: list is empty,nothing to delete" << endl;
        return;
      }
      if(head->data == value){  //check if desired value is at head
        Node* current = head; //create a pointer to point at head
        head = head->next; //let the second node be the head
        delete current; //delete the previous head (desired value)
        length--; //modify the length by decreasing
        return;
      }
      Node* current = head; //create a pointer that points to the head
      while (current->next != nullptr && current->next->data != value){ //traverse through the list till the desired value is found or till null is reached
        current = current->next;
        }
        if (current->next == nullptr){ //if null is reached then value does not exist
          cerr << "error: node does not exist, desired value is not found" << endl;
          return;
        }
        if (current->next->data == value){ //if value is found
        Node* current2 = current->next; //create new pointer that points to the desired value
        current->next = current->next->next; //let the first pointer point to the next of the desired value
        delete current2->next; //delete the desired node
        length--; //modify the length by decreasing
        }
      }

void LinkedList::swapNodes(Node *node1, Node *node2) {
     //if two nodes are the same , no need to swap
    if (node1 == node2)
        return;
    Node*cur = head; //create a new pointer that starts at head

    //swap the next pointers of each node
    cur->next = node1->next;
    node1->next = node2->next;
    node2->next = cur->next;
}

//public getter to access nodes
LinkedList::Node *LinkedList::getNodeAt(int index) const {
    if (index < 0 || index >= length)
        return nullptr;
    Node* cur = head;
    for (int i = 0; i < index; ++i)
    {
        cur = cur->next;
    }
    return cur;
}
LinkedList::Node* LinkedList::createNode(int data) {
    return new Node(to_string(data));
}

void LinkedList::appendNode(Node*& h, int data) {
    Node* n = createNode(data);
    if (!h) h=n;
    else { Node* cur=h; while(cur->next) cur=cur->next; cur->next=n; }
}

LinkedList::Node* LinkedList::reverseList(Node* h) {
    if (!h||!h->next) return h;
    Node* newH = reverseList(h->next);
    h->next->next = h;
    h->next = nullptr;
    return newH;
}

LinkedList::Node* LinkedList::reverseKGroup(Node* h, int k) {
    if(k<=1||!h) return h;
    Node dummy(""), *prev=&dummy;
    dummy.next = h;
    int count=0; for(Node* cur=h; cur; cur=cur->next) ++count;
    while(count>=k){
        Node* start=prev->next, *end=start;
        for(int i=1;i<k;++i) end=end->next;
        Node* nxt = end->next;
        // reverse
        Node* p=nxt;
        for(Node* c=start; c!=nxt; ){ Node* t=c->next; c->next=p; p=c; c=t; }
        prev->next=p;
        prev=start;
        count-=k;
    }
    return dummy.next;
}

LinkedList::Node* LinkedList::getPreviousNode(Node* h, Node* target) {
    if(!h||h==target) return nullptr;
    for(Node* cur=h; cur->next; cur=cur->next)
        if(cur->next==target) return cur;
    return nullptr;
}

LinkedList::Node* LinkedList::getMiddleNode(Node* h) {
    Node *slow=h, *fast=h;
    while(fast&&fast->next){ slow=slow->next; fast=fast->next->next; }
    return slow;
}

LinkedList::Node* LinkedList::getNthFromEnd(Node* h, int k) {
    Node *fast=h,*slow=h;
    for(int i=0;i<k&&fast;i++) fast=fast->next;
    while(fast){ slow=slow->next; fast=fast->next; }
    return slow;
}

LinkedList::Node* LinkedList::getNthNode(Node* h, int n) {
    for(int i=0; i<n&&h; ++i) h=h->next;
    return h;
}

LinkedList::Node* LinkedList::getHead(Node* h) { return h; }
LinkedList::Node* LinkedList::getTail(Node* h) { Node* cur=h; while(cur&&cur->next) cur=cur->next; return cur; }

void LinkedList::printList(Node* h) {
    if(!h){ cout<<"List is empty"<<endl; return; }
    Node* cur=h;
    while(cur){ cout<<cur->data; if(cur->next) cout<<" -> "; cur=cur->next; }
    cout<<" -> NULL"<<endl;
}

void LinkedList::freeList(Node* h) {
    while(h){ Node* t=h->next; delete h; h=t; }
}

void LinkedList::reverseLinkedList() {
    head = reverseList(head);
}
