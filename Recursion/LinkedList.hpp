#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node *next;
    Node (int v) {
        value = v;
    }
};

class SinglyLinkedList {
public:
    Node *head;
    int size;

    SinglyLinkedList () {
        head = nullptr;
        size = 0;
    }

    void insert(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            node->next = nullptr;
            head = node;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }

    void pop() {
        if (head == nullptr) {
            return;
        } else if (head->next == nullptr) {
            head = nullptr;
        } else {
            Node *value = head;
            head = head->next;
            delete value;
        }
        size--;
    }

    void display() {
        Node *node = head;
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->next;
        }
    }
};

void display(Node *head) {
    Node *node = head;
    while (node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }
}