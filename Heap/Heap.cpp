#include <iostream>
using namespace std;

class Heap {
public:
    int arr[1000] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n;

    Heap () {
        n = 10;
    }

    void heapifyUp(int *arr, int n, int i) {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyUp(arr, n, largest);
        }
    }

    void heapifyMin(int *arr, int n, int i) {
        int smallest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        
        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyMin(arr, n, smallest);
        }
    }

    void buildMinHeap() {
        for (int i=(n/2-1); i > -1; i--) {
            heapifyMin(arr, n, i);
        }
    }

    void buildMaxHeap() {
        for (int i=(n/2-1); i > -1; i--) {
            heapifyUp(arr, n, i);
        }
    }

    void display() {
        for (int i=0; i<n; i++) {
            cout << arr[i] << " , ";
        }
        cout << endl;
    }

    void heapifyDown(int *arr, int n, int i) {
        int parent = (i-1)/2;

        if (parent > -1) {
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                heapifyDown(arr, n, parent);
            }
        }
    }

    void insertNode(int value) {
        arr[n] = value;
        n += 1;
        heapifyDown(arr, n, n-1); 
    }

    void deleteRoot() {
        arr[0] = arr[n-1];
        n--;
        heapifyUp(arr, n, 0);
    }
};

int main() {

    Heap heap;

    heap.display();

    heap.buildMaxHeap();

    heap.insertNode(54);
    heap.insertNode(45);
    heap.insertNode(34);

    heap.display();

    heap.deleteRoot();
    cout << "Deleted" << endl;
    heap.display();

    return 0;
}