#include <iostream>
#include "Stack.hpp"
using namespace std;

bool isNumber(char c) {
    if (c > 47 and c < 58) {
        return true;
    }
    return false;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

int solvePostfix(string str) {
    Stack stack;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (isNumber(c)) {
            stack.push(c - 48);
        } else if (isOperator(c)) {
            int val1 = stack.getTop()->value;
            stack.pop();
            switch (c)
            {
            case '+':
                stack.getTop()->value += val1;
                break;
            case '-':
                stack.getTop()->value -= val1;
                break;
            case '*':
                stack.getTop()->value *= val1;
                break;
            case '/':
                stack.getTop()->value /= val1;
                break;
            default:
                break;
            }
        }
        else {
            cout << "Invalid character " << c <<  " at " << i << " " << endl;
            break;
        }
    }

    return stack.getTop()->value;

}

int main() {

    string str = "234*+";
    int answer = solvePostfix(str);

    cout << answer << endl;



    return 0;
}
