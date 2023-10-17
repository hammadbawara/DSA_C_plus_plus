#include <iostream>
using namespace std;

class Node {
public:
    Node *next;
    int priorty;
    int value;
    Node(int v, int p) {
        value = v;
        priorty = p;
        next = nullptr;
    }
};

class PriortyQueue {
public:
    Node *first;
    int size;
    PriortyQueue() {
        first = nullptr;
        size = 0;
    }

    void enqueue(int value, int priorty) {
        Node* newNode = new Node(value, priorty);
        if (first == nullptr) {
            first = newNode;
        }else {
            Node *node = first;
            while (node->next != nullptr && node->next->priorty >= newNode->priorty) {
                node = node->next;
            }
            if (node == first) {
                newNode->next = node;
                first = newNode;
            }else {
                newNode->next = node->next;
                node->next = newNode;
            }   
        }
        size++;
    }

    void display() {
        Node *node = first;
        while (node != nullptr) {
            //cout << "(" <<node->value << ", " << node->priorty << "), ";
            cout << node->value << ", ";
            node = node->next;
        }
        cout << endl;
    }

    void print(Node *temp) {
        if (temp == nullptr) {
            return;
        }
        print(temp->next);
        cout << temp->value << ", ";
    }


};

int main() {

    PriortyQueue queue;

    queue.enqueue(1, 1);
    
    queue.enqueue(2, 2);
    queue.enqueue(3, 2);
    queue.enqueue(4, 1);
    queue.enqueue(5, 3);
    queue.enqueue(6, 3);

    queue.enqueue(7, 1);
    queue.enqueue(8, 2);

    queue.display();


    return 0;
}