// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

#include <iostream>
using namespace std;

int multiply(int num1, int num2) {
    if (num2 == 1) {
        return num1;
    }

    return num1 + multiply(num1, num2-1);
}

int main() {

    cout << multiply(5, 4);


    return 0;
}