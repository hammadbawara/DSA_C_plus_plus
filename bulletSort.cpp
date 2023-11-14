#include <iostream>
using namespace std;

int main() {

    int arr[] = {3, 4, 2, 1};

    int size = sizeof(arr) / 4;

    for (int i = 0; i<size; i++) {
        for (int j = 0; j<(size - i - 1); j++) {
            if (arr[j] > arr[j+ 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    cout << "[";
    for (int i= 0 ; i<size -1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << "]" << endl;
    return 0;
}