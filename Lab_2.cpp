/*
NAME : HAMMAD ZAFAR
ROLL NO : 2022-CS-639 (A)
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value, Node *next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

class LinkedList
{
private:
    Node *first = nullptr;
    Node *last = nullptr;
    int size = 0;

public:
    LinkedList() {}

    void insertAtEnd(int value)
    {
        Node *node = new Node(value);
        if (first == nullptr || last == nullptr)
        {
            first = node;
            last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
        size++;
    }

    void insertAtBegin(int value)
    {
        if (size == 0)
        {
            insertAtEnd(value);
        }
        else
        {
            Node *node = new Node(value, first);
            first = node;
        }
    }

    void display()
    {
        if (size == 0)
        {
            cout << "[]\n";
        }
        else
        {
            Node *node = first;
            cout << "[";
            do
            {
                cout << node->value;
                if (node->next != nullptr)
                {
                    cout << " -> ";
                }
                node = node->next;
            } while (node != nullptr);
            cout << "]" << endl;
        }
    }

    void update(int index, int value)
    {
        if (-1 < index && index < size)
        {
            Node *node = first;
            for (int i = 0; i < index; i++)
            {
                node = node->next;
            }
            node->value = value;
        }
        else
        {
            throw exception();
        }
    }

    int search(int value)
    {
        Node *node = first;
        int i = 0;
        while (node != nullptr)
        {
            if (node->value == value)
            {
                return i;
            }
            node = node->next;
            i++;
        }
        return -1;
    }

    void insertAfter(int index, int value)
    {
        if (-1 < index && index < size)
        {
            Node *node = first;
            for (int i = 0; i < index - 1; i++)
            {
                node = node->next;
            }
            node->next = new Node(value, node->next);
            size++;
        }
        else
        {
            throw exception();
        }
    }

    void sortAsceding() {
        for (int i=0; i<size; i++) {
            Node *node = first;
            for (int j = 1; j < (size - i); j++) {
                if (node->value > node->next->value) {
                    int temp = node->value;
                    node->value = node->next->value;
                    node->next->value = temp;
                }
                node = node->next;
            }
        }
    }
    void sortDeasceding()
    {
        for (int i = 0; i < size; i++)
        {
            Node *node = first;
            for (int j = 1; j < (size - i); j++)
            {
                if (node->value < node->next->value)
                {
                    int temp = node->value;
                    node->value = node->next->value;
                    node->next->value = temp;
                }
                node = node->next;
            }
        }
    }

    void reverse() {
        if (size > 1) {
            Node *prev = nullptr;
            Node *current = first;
            Node *next = first->next;

            while (next != nullptr)
            {
                current->next = prev;
                prev = current;
                current = next;
                next = next->next;
            }
            current->next = prev;
            first = current;
        }
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    LinkedList ll;

    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);

    cout << "Reversing " << endl;
    ll.reverse();
    ll.display();

    return 0;
}
