#include <iostream>
using namespace std;

class Node {
public:
    char value;
    Node *next;

    Node(char value) {
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

    void push(char value) {
        Node *newTopNode = new Node(value);
        if (isEmpty()) {
            top = newTopNode;
        }else {
            newTopNode->next = top;
            top = newTopNode;
        }
        size++;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }else {
            return false;
        }
    }

    char pop() {
        Node* temp = top;
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
        return top->value;
        size--;
    }

    void print() {
        if (isEmpty()) {
            return;
        }

        Node *node = top;
        while (node != nullptr) {
            cout << node->value;
            node = node->next;
        }
        cout << endl;
    }

    void popAll() {
        Node* node = top;
        while (node != nullptr) {
            cout << node->value;

            node = node->next;
        }
        top = nullptr;
    }
};

int main() {
    cout << "Enter string: ";
    string line;
    getline(cin, line);

    Stack stack = Stack();
    for (int i=0; i<line.length(); i++) {
        if (line[i] == ' ') {
            stack.popAll();
            cout << " ";
        }
        
        stack.push(line[i]);
    }

    stack.popAll();

    return 0;
}