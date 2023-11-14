// NAME: HAMMAD ZAFAR
// ROLL NO : 2022-CS-639 (A)

#include <iostream>
using namespace std;

int nthPower(int num, int power) {
    if (power == 0) {
        return 1;
    }
    int result = nthPower(num, power-1);
    return num*result;
}

int main() {

    cout << nthPower(5, 4) << endl;

    return 0;
}