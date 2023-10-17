// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int searchValue(Node* head, int value, int iteration = 0) {
    if (head->next == nullptr) {
        return -1;
    }else if (head->value == value) {
        return iteration;
    }

    return searchValue(head->next, value, iteration+1);
}

int main() {

    DoublyLinkedList ll;
    for (int i=0; i<10; i++) {
        ll.insert(i);
    }

    cout << searchValue(ll.head, 12) << endl;
    cout << searchValue(ll.head, 2) << endl;
    cout << searchValue(ll.head, -6) << endl;
    cout << searchValue(ll.head, 7) << endl;




    return 0;
}