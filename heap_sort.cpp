/*
 * Author      : Midhun P
 * Description : Heap sort
 * Remarks     : Worst : O(n*log(n)) Best : O(n*log(n))
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void build_max_heap(int *arr, int n) {
    for(int i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, i);
}

void heap_sort(int *arr, int n) {
    // Build max heap
    build_max_heap(arr, n);

    // Save the root element in the opposite order
    for(int i = n-1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    heap_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}