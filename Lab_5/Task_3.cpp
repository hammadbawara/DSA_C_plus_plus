#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

bool isBalanced(string str) {
    Stack stack;
    for (int i = 0; i < str.length(); i++) {
        if (isStarting(str[i])) {
            stack.push(str[i]);
        } else {
            if (stack.getTop() == nullptr) {
                return false;
            }
            if (getOposite(str[i]) == stack.getTop()->value){
                stack.pop();
            }else {
                return false;
            }
        }
    }
    if (stack.size != 0) {
        return false;
    }
    return true;
}

void checkSequence(string str) {
    bool isCorrect = isBalanced(str);

    cout << str << endl;
    if (isCorrect) {
        cout << "Correct Sequence" << endl;
    }else {
        cout << "Wrong Sequence" << endl;
    }
    cout << endl;
}

int main() {

    checkSequence("{}{}{{})");
    checkSequence("{{{(})}}");
    checkSequence("{{{()}}}{}(()){}");
    
    return 0;
}