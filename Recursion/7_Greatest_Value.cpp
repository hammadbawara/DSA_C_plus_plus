#include <iostream>
#include "LinkedList.hpp"
using namespace std;

Node* greatestValue(Node *head) {
    if (head->next == nullptr) {
        return head;
    }

    Node *val = greatestValue(head->next);
    if (val->value > head->value) {
        return val;
    }else {
        return head;
    }
}

int main() {

    DoublyLinkedList dll;

    dll.insert(4);
    dll.insert(3);
    dll.insert(1);
    dll.insert(7);
    dll.insert(9);
    dll.insert(2);

    Node* greatestValueNode = greatestValue(dll.head);

    cout << greatestValueNode->value << endl;    


    return 0;
}