// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

#include <iostream>
using namespace std;

int factorial(int num) {
    if (num == 1) {
        return 1;
    }
    return num * factorial(num -1);
}

int main() {

    cout << factorial(5) << endl;


    return 0;
}