#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Stack {
    
public:
    int size;
    Node *top;
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int value) {
        Node *newTopNode = new Node(value);
        if (isEmpty()) {
            top = newTopNode;
        }else {
            newTopNode->next = top;
            top = newTopNode;
        }
        size++;
    }

    void pop() {
        if (!isEmpty()) {
            if (size == 1) {
                delete top;
                top = nullptr;
            }else {
                Node *prev = top->next;
                delete top;
                top = prev;
            }
        }
        size--;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }else {
            return false;
        }
    }

    void print() {
        if (isEmpty()) {
            return;
        }

        Node *node = top;
        cout << "[";
        while (node->next != nullptr) {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << node->value << "]" << endl;
    }

    Node* get(int index) {
        Node *indexNode = top;
        if (index > -1 && index < size) {
            for (int i = 0; i < index; i++) {
                indexNode = indexNode->next;
            }
        }
        return indexNode;
    }

    void print(int index) {
        cout << get(index)->value << endl;
    }

    Node* getTop() {
        return top;
    }
};

bool isStarting(char c) {
    if (c == '{' || c == '(' || c == '[') {
        return true;
    }
    return false;
}

char getOposite(char c) {
    if (c == '}') {
        return '{';
    }else if (c == ']') {
        return '[';
    }else if (c == ')') {
        return '(';
    }else {
        return '0';
    }
}