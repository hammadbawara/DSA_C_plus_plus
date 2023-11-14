// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

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

Node* reverse(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *reset = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reset;
}

int sum(int num) {
    if (num == 1) {
        return 1;
    }
    int n = num + sum(num - 1);
    return n;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int num) {
    if (num == 1) {
        return 1;
    }
    return num * factorial(num -1);
}


int main() {

    // Reverse Singly Linked List by Recursion
    SinglyLinkedList ll;

    for (int i = 1; i < 5; i++) {
        ll.insert(i);
    }

    Node *head = reverse(ll.head);
    display(head);

    // Sum by Recursion
    cout << "\n Sum by Recursion" << endl;
    cout << sum(5) << endl;

    cout << "\n Fabonacci Number" << endl;
    cout << fibonacci(5);

    cout << "\nFactorial " << endl;
    cout << factorial(5);

    return 0;
}