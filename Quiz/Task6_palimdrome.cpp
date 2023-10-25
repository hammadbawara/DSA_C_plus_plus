#include <iostream>
using namespace std;
class Node {
public:
    char value;
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

    char pop() {
        char temp = top->value;
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
        cout << "[";
        while (node->next != nullptr) {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << node->value << "]" << endl;
    }

};

int checkPalimdrome(string line) {
    Stack stack = Stack();
    int half = line.length()/2;

    if (line.length() % 2 != 0) {
        half = line.length()/2 + 1;
    }

    for (int i=0; i<half; i++) {
        stack.push(line[i]);
    }

    if (line.length() % 2 != 0) {
        stack.pop();
    }

    for (int i=half; i<line.length(); i++) {
        if (line[i] != stack.pop()) {
            return false;
        }
    }
    return true;
}




int main() {
    string line;

    getline(cin, line);

    if(checkPalimdrome(line)){
        cout << line << " is  palimdrome" << endl;
    } else {
        cout << line << " is not a palimdrome" << endl;
    }

}