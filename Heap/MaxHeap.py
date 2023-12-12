def heapify_max(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    print("largest =", largest, " -> ", arr[largest])
    try:
        print("left =", left, " -> ", arr[left])
    except:
        print("left = ", left)
    try:
        print("right =", right, " -> ", arr[right])
    except:
        print("right = ", right)

    print("array = ", arr,)
    print("")


    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify_max(arr, n, largest)

def build_max_heap(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        print("-Build Max Heap-")
        print(arr)
        heapify_max(arr, n, i)
        print()

# Example usage:
arr = [4, 10, 3, 5, 1, 7]
print("Original Array:", arr)

# Max heapify the array
build_max_heap(arr)

print("Max Heapified Array:", arr)