// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    cout << fibonacci(9);

    return 0;
}