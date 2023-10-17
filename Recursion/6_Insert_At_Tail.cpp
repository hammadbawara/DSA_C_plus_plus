#include <iostream>
#include "LinkedList.hpp"
using namespace std;

void insertAtTail(Node *head, int value) {
    if (head->next == nullptr) {
        Node *node = new Node(value);
        node->next = nullptr;
        head->next = node;
        return;
    }
    insertAtTail(head->next, value);
}

int main() {

    DoublyLinkedList ll;
    for (int i=0; i<10; i++) {
        ll.insert(i);
    }

    insertAtTail(ll.head, 11);

    ll.display();


    return 0;
}