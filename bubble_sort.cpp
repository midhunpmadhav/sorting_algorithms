/*
 * Author      : Midhun P
 * Description : Bubble sort
 * Remarks     : Worst: O(n^2) Best: O(n^2) without optimization, O(n) with optimization
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

// Function for optimized bubble sort.
void bubble_sort(int *arr, int n) {
    for(int i = 0; i < n-1; ++i) {
        bool swap_done = false;
        for(int j = 0; j < n-i-1; ++j)
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swap_done = true;
            }
        if(!swap_done)
            break;
    }
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    bubble_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}