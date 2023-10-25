#include <iostream>
#include "SinglyLinkedList.hpp"
using namespace std;

int main() {
    SinglyLinkedList sll = SinglyLinkedList();

    for (int i = 0; i < 10; i++) {
        sll.push(i + 1);
    }

    sll.display();

    Node* current = sll.head;

    while (current != nullptr && current->next != nullptr) {
        int temp = current->value;
        current->value = current->next->value;
        current->next->value = temp;
        current = current->next->next;
    }

    sll.display();

    return 0;
}
