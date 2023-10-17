#include <iostream>
using namespace std;


int fab(int num) {
    if (num <= 2) {
        return 1;
    }
    return fab(num-1) + fab(num-2);
}

int main() {

    cout << fab(8);


    return 0;
}