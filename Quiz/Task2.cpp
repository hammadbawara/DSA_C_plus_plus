#include <iostream>
#include "SinglyLinkedList.hpp"
using namespace std;

int main() {

    SinglyLinkedList sll = SinglyLinkedList();

    for (int i=0; i<10; i++) {
        sll.push(i + 1);
    }

    sll.display();

    int appendAt = 3;
    
    Node *newEnd = sll.head;
    for (int i=0; i< appendAt -1; i++) {
        newEnd = newEnd->next;
    }

    sll.tail->next = sll.head;
    sll.head = newEnd->next;
    newEnd->next = nullptr;

    sll.display();

    

    

    

    return 0;
}