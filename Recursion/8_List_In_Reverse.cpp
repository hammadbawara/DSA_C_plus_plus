// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

#include <iostream>
#include "LinkedList.hpp"
using namespace std;

void reverseDisplay(Node* head) {
    if (head->next == nullptr) {
        return;
    }
    reverseDisplay(head->next);
    cout << head->value << " ";
}

int main() {

    DoublyLinkedList ll;
    for (int i=0; i< 10; i++) {
        ll.insert(i);
    }

    
    ll.display();


    reverseDisplay(ll.head);
    

    return 0;
}