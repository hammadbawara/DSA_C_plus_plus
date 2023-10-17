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
    Node *prev;

    Node(int value) {
        this->value = value;
    }
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;
    int size;
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }
    void insert(int value) {
        Node *newNode = new Node(value);
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
        }else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size += 1;
    }

    void insertAtIndex(int index, int value) {
        if (index > 0 && index < size) {
            Node *newNode = new Node(value);
            Node *current = head;
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
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }else {
            newNode->next = nullptr;
            newNode->next = head;
            head->next = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtLast(int value) {
        Node *newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = nullptr;
            newNode->next = tail;
            tail = newNode;
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
            Node *current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            if (current->next == nullptr) {
                current->next->next = nullptr;
                head = current->next;
            }else if (current->next == nullptr) {
                current->next->next = nullptr;
                tail = current->next;
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
        tail = tail->next;
        delete tail->next;
        tail->next = nullptr;
        size--;
    }

    void deleteFirst() {
        if (size == 0) {
            return;
        }
        this->head = this->head->next;
        delete head->next;
        head->next = nullptr;
        size--;
    }

    void display()
    {
        cout << "[";
        Node *current = head;
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
        Node *current = tail;
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

    void pop() {
        deleteLast();
    }

    void reverse() {
        if (size == 0) {
            return;
        }else {
            Node *current = tail;
            for (int i = 0; i < size; i++) {
                Node *newNext = current->next;
                Node *newPrev = current->next;

                current->next = newNext;
                current->next = newPrev;
                current = newNext;
            }
            Node *temp = head;
            head = tail;
            tail = temp;
        }
    }
};