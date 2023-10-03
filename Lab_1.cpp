/*
NAME : HAMMAD ZAFAR
ROLL NO: 2022-CS-639 (A)
*/
#include <iostream>
using namespace std;

class ArrayList {
private:
    int *arr;
    int size;

public:
    ArrayList() {
        arr = nullptr;
        size = 0;
    }
    
    void insert(int value) {
        if (arr == nullptr) {
            arr = new int[1]{value};
        }else {
            int *temp = new int[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            temp[size] = value;
            delete arr;
            arr = temp;
        }
        size++;
    }

    void insertAtBegining(int value) {
        if (size == 0) {
            insert(value);
        }else {
            size++;
            int *temp = new int[size];
            for (int i = 1; i < size; i++)
            {
                temp[i] = arr[i];
            }
            temp[0] = value;
            delete arr;
            arr = temp;
        }
    }

    void insertAtEnd(int value) {
        insert(value);
    }

    void removeAt(int index) {
        if (index > -1 && index < size) {
            if (size == 1) {
                delete arr;
                arr = nullptr;
            }else {
                
                int *temp = new int[size - 1];
                int j = 0;
                for (int i = 0; i < size; i++) {
                    if (i != index) {
                        temp[j] = arr[i];
                        j++;
                    }
                }
                delete arr;
                arr = temp;
            }
            size--;
        }
    }

    int search(int value) {
        for (int i = 0; i<size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void remove(int value){
        int index = search(value);
        if (index != -1) {
            removeAt(index);
        }
    }

    void display() {
        if (arr==nullptr) {
            cout << "[]" << endl;
        }else {
            cout << "[";
            for (int i = 0; i < size; i++) {
                cout << *arr + i << ", ";
            }
            cout << "]";
        }
    }

    // Function to remove a value after a specific value in the list.
    void removeAfterValue(int target)
    {
        int index = search(target);
        if (index != -1 && index < size - 1)
        {
            removeAt(index + 1);
        }
    }

    // Function to update a value at a certain index of the array with a new value.
    void update(int index, int newValue)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = newValue;
        }
    }

    // Function to show proper message according to the current index of the array.
    void indexAt(int currentIndex)
    {
        if (currentIndex < 0 || currentIndex >= size)
        {
            cout << "Invalid index." << endl;
        }
        else
        {
            cout << "Current index is: " << currentIndex << endl;
        }
    }
};

int main() {

    ArrayList list = ArrayList();

    for (int i = 0; i < 100; i++) {
        list.insert(i+1);
    }

    list.removeAt(1);
    list.removeAt(50);

    list.insertAtBegining(1);
    list.insertAtEnd(17);
    list.removeAfterValue(3);

    list.display();

    list.update(2, 10);
    list.indexAt(2);

    list.display();
}