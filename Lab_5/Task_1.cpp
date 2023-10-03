#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int top = -1;
public:

    void push(int value){
        if (!isFull) {
            top++;
            arr[top] = value;
        }else {
            cout << "Array is full" << endl;
        }   
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == 9) {
            return true;
        }
        return false;
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    void printTop() {
        cout << arr[top] << endl;
    }

    void print() {
        cout << "[";
        for (int i = top; i > -1; i--) {
            cout << arr[i] << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {

    Stack stack;

    for (int i = 0; i < 10; i++) {
        stack.push(i + 1);
    }

    stack.print();

    stack.pop();

    stack.print();
    
    return 0;
}