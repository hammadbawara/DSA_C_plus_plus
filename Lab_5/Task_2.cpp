#include <iostream>
using namespace std;

class Node
{
public:
    char value;
    Node *next;

    Node(char value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void push(char value)
    {
        Node *newTopNode = new Node(value);
        if (isEmpty())
        {
            top = newTopNode;
        }
        else
        {
            newTopNode->next = top;
            top = newTopNode;
        }
        size++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            if (size == 1)
            {
                delete top;
                top = nullptr;
            }
            else
            {
                Node *prev = top->next;
                delete top;
                top = prev;
            }
        }
        size--;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            return;
        }

        Node *node = top;
        cout << "[";
        while (node->next != nullptr)
        {
            cout << node->value << ", ";
            node = node->next;
        }
        cout << node->value << "]" << endl;
    }

    Node *get(int index)
    {
        Node *indexNode = top;
        if (index > -1 && index < size)
        {
            for (int i = 0; i < index; i++)
            {
                indexNode = indexNode->next;
            }
        }
        return indexNode;
    }

    void print(int index)
    {
        cout << get(index)->value << endl;
    }
};

int main()
{

    Stack stack;

    for (int i = 0; i < 10; i++)
    {
        stack.push(65 + i);
    }
    stack.print();

    stack.print(3);
    return 0;
}