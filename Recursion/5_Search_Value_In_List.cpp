#include <iostream>
#include "SinglyLinkedList.hpp"
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

    SinglyLinkedList sll;
    for (int i=0; i<10; i++) {
        sll.insert(i);
    }

    cout << searchValue(sll.head, 12) << endl;
    cout << searchValue(sll.head, 2) << endl;
    cout << searchValue(sll.head, -6) << endl;
    cout << searchValue(sll.head, 7) << endl;




    return 0;
}