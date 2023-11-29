#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty\n";
            return -1; // or any suitable value indicating an error
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    void printHeap() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxHeap maxHeap;

    // Insert elements into the max heap
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(1);
    maxHeap.insert(12);
    maxHeap.insert(7);

    std::cout << "Max Heap: ";
    maxHeap.printHeap();

    // Extract the maximum element
    std::cout << "Extracted Max: " << maxHeap.extractMax() << "\n";

    std::cout << "Max Heap after extraction: ";
    maxHeap.printHeap();

    return 0;
}
