#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

  
    void enQueue(int value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        rear->next = front; 
    }


    void deQueue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot deQueue." << endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }


    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4);

    cout << "Initial queue: ";
    cq.display();

    cq.deQueue();
    cout << "After deQueue: ";
    cq.display();

    cq.enQueue(5);
    cout << "After enQueue(5): ";
    cq.display();

    return 0;
}
