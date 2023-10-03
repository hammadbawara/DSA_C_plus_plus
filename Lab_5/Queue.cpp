#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int v)
    {
        value = v;
        next = nullptr;
    }
};

class Queue
{
public:
    Node *first;
    Node *last;
    int size;
    Queue()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (first == nullptr)
        {
            first = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;
        size++;
    }

    void pop()
    {
        if (first != nullptr)
        {
            if (first == last)
            {
                delete last;
                first = nullptr;
                last = nullptr;
            }
            else
            {
                Node *newLast = last->next;
                delete last;
                newLast = last;
            }
        }
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        Node *node = first;
        cout << "[";
        while (node->next != nullptr)
        {
            cout << node->value << " -> ";
            node = node->next;
        }
        cout << node->value << "]" << endl;
    }
};

int main()
{
    Queue q;
    q.push(2);
    q.push(200);
    q.push(300);

    q.display();
}