/*
NAME    : HAMMAD ZAFAR
ROLL NO : 2022-CS-639 (A)
*/

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value) {
        this->value = value;
    }
};

class DoublyLinkedList {
    Node *first;
    Node *last;
    int size;

public:
    DoublyLinkedList() {
        this->first = nullptr;
        this->last = nullptr;
        size = 0;
    }
    void insert(int value) {
        Node *newNode = new Node(value);
        newNode->next = nullptr;
        if (first == nullptr) {
            newNode->prev = nullptr;
            first = newNode;
            last = newNode;
        }else {
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        size += 1;
    }

    void insertAtIndex(int index, int value) {
        if (index > 0 && index < size) {
            Node *newNode = new Node(value);
            Node *current = first;
            for (int i = 0; i<index; i++) {
                current = current->next;
            }
            newNode->prev = current->prev;
            newNode->next = current->next;
            current->prev->next = newNode;
            current->next->prev = newNode;
        }
        else if (index == 0) {
            insertAtStart(value);
        }
        else if (index == size) {
            insertAtLast(value);
        }
        else {
            exception();
        }
    }

    void insertAtStart(int value) {
        Node *newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }else {
            newNode->prev = nullptr;
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        size++;
    }

    void insertAtLast(int value) {
        Node *newNode = new Node(value);
        if (last == nullptr) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            newNode->next = nullptr;
            newNode->prev = last;
            last = newNode;
        }
        size++;
    }

    void print() {
        display();
    }

    void printReverse() {
        displayBackward();
    }

    void deleteAtIndex(int index) {
        if (-1 < index && index < size) {
            Node *current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            if (current->prev == nullptr) {
                current->next->prev = nullptr;
                first = current->next;
            }else if (current->next == nullptr) {
                current->prev->next = nullptr;
                last = current->prev;
            }else {
                Node *prev = current->prev;
                Node *next = current->next;
                prev->next = current->next;
                next->prev = current->prev;
            }
            size--;
            delete current;
        }
    }

    void insertLast(int value) {
        insert(value);
    }

    void deleteLast() {
        if (size == 0) {
            return;
        }
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        size--;
    }

    void deleteFirst() {
        if (size == 0) {
            return;
        }
        this->first = this->first->next;
        delete first->prev;
        first->prev = nullptr;
        size--;
    }

    void display()
    {
        cout << "[";
        Node *current = first;
        while (current->next != nullptr)
        {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << current->value << "]" << endl;
    }

    void displayForward() {
        display();
    }

    void displayBackward() {
        cout << "[";
        Node *current = last;
        while (current->prev != nullptr) {
            cout << current->value;
            current = current->prev;
            cout << " <- ";
        }
        cout << current->value << "]" << endl;
    }

    void insertMiddle(int value) {
        if (size == 0) {
            insert(value);
        }else {
            int middleIndex = size / 2;
            insertAtIndex(middleIndex, value);
        }
    }

    void deleteMiddle() {
        if (size == 0) {
            return;
        }else {
            int middleIndex = size / 2;
            deleteAtIndex(middleIndex);
        }
    }

    void reverse() {
        if (size == 0) {
            return;
        }else {
            Node *current = last;
            for (int i = 0; i < size; i++) {
                Node *newNext = current->prev;
                Node *newPrev = current->next;

                current->next = newNext;
                current->prev = newPrev;
                current = newNext;
            }
            Node *temp = first;
            first = last;
            last = temp;
        }
    }
};

int main() {

    DoublyLinkedList ll = DoublyLinkedList();
    
    cout << "Inserting 0, 1, 2, 3, 4, 5" << endl;

    ll.insert(0);
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);

    ll.display();

    cout << "\nInserting at start 11" << endl;
    ll.insertAtStart(11);
    ll.display();

    cout << "\nInserting at last 12" << endl;
    ll.insertAtLast(12);
    ll.display();

    cout << "\nInserting at index 3" << endl;
    ll.insertAtIndex(3, 80);
    ll.display();

    cout << "\nInserting at middle 8" << endl;
    ll.insertMiddle(8);
    ll.display();

    cout << "\nDeleting at middle" << endl;
    ll.deleteMiddle();
    ll.display();

    cout << "\nDeleting at index 3" << endl;
    ll.deleteAtIndex(3);
    ll.display();

    cout << "\nDeleting first" << endl;
    ll.deleteFirst();
    ll.display();

    cout << "\nDeleting last" << endl;
    ll.deleteLast();
    ll.display();

    cout << "\nDisplaying Backward" << endl;
    ll.displayBackward();

    cout << "\nReversing List" << endl;
    ll.reverse();
    ll.display();

    return 0;
}