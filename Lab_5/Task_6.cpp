#include <iostream>
#include <math.h>
#include "Stack.hpp"
using namespace std;

bool isNumber(char c) {
    if (c > 47 && c < 58) {
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

int precedenceOf(char c) {
   if (c == '*' || c == '/') {
        return 2;
   } else if (c == '+' || c == '-') {
        return 1;
   } else {
        return -1;
   }
}

void infixToPrefix(string expression) {
    Stack operatorStack;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == '(') {
            operatorStack.push(c);

        } else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.getTop()->value != '(') {
                cout << (char) operatorStack.getTop()->value;
                operatorStack.pop();
            }
            if (!operatorStack.isEmpty() && operatorStack.getTop()->value == '(') {
                operatorStack.pop();
            }
        }
        else if (isOperator(c)) {
            if (operatorStack.isEmpty()) {
                operatorStack.push(c);
            }else {
                while (
                        !operatorStack.isEmpty() && 
                        precedenceOf(operatorStack.getTop()->value) >= precedenceOf(c)
                    ) {
                        cout << (char) operatorStack.getTop()->value;
                        operatorStack.pop();
                    }
                operatorStack.push(c);
            }
        } else {
            cout << c;
        }
    }

    while (!operatorStack.isEmpty()) {
        cout << (char) operatorStack.getTop()->value;
        operatorStack.pop();
    }
}





int main() {

    string express = "3*(4+5*(9/6)+7)-3";

    infixToPrefix(express);
    return 0;
}