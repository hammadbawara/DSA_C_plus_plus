/*
NAME    : HAMMAD ZAFAR
ROLL NO : 2022-CS-639 (A)
*/

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
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
            newNode->next = nullptr;
            first = newNode;
            last = newNode;
        }else {
            newNode->next = last;
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
            newNode->next = current->next;
            newNode->next = current->next;
            current->next->next = newNode;
            current->next->next = newNode;
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
            newNode->next = nullptr;
            newNode->next = first;
            first->next = newNode;
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
            newNode->next = last;
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
            if (current->next == nullptr) {
                current->next->next = nullptr;
                first = current->next;
            }else if (current->next == nullptr) {
                current->next->next = nullptr;
                last = current->next;
            }else {
                Node *prev = current->next;
                Node *next = current->next;
                prev->next = current->next;
                next->next = current->next;
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
        last = last->next;
        delete last->next;
        last->next = nullptr;
        size--;
    }

    void deleteFirst() {
        if (size == 0) {
            return;
        }
        this->first = this->first->next;
        delete first->next;
        first->next = nullptr;
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
        while (current->next != nullptr) {
            cout << current->value;
            current = current->next;
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
                Node *newNext = current->next;
                Node *newPrev = current->next;

                current->next = newNext;
                current->next = newPrev;
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