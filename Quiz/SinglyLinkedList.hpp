#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node(int v) {
        value = v;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node *head;
    Node *tail;
    int size;
    
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
        size ++;
    }

    void pop() {
        if (tail == nullptr) {
            cout << "linked is empty. No element to pop" << endl;
        }else if(head == tail) {
            head == nullptr;
            tail = nullptr;
        } else {
            Node *node = head;
            for (int i=0; i<size - 1 ; i++) {
                node = node->next;
            }
            tail = node;
        }
    }

    void display() {
        if (head ==  nullptr) {
            cout << "No element to display." <<endl;
            return;
        }
        Node *node = head;
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;

    }
};