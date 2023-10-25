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

    int pop() {
        int temp = top->value;
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
        return temp;
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
        while (node->next != nullptr) {
            cout << node->value << " ";
            node = node->next;
        }
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




int main() {

    Stack stack = Stack();

    stack.push(1);
    stack.push(9);
    stack.push(-1);
    stack.push(-9);
    stack.push(-34);
    stack.push(-23);
    stack.push(6);
    stack.push(-12);
    stack.push(5);
    stack.push(6);

    Node *node = stack.top;

    Stack negativeStack = Stack();

    Stack positiveStack = Stack();

    for (int i=0; i<stack.size; i++) {
        if (node->value > 0) {
            positiveStack.push(node->value);
        }else {
            negativeStack.push(node->value);
        }
        node = node->next;
    }

    negativeStack.print();
    positiveStack.print();
    
    





}