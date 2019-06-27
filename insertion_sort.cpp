/*
 * Author      : Midhun P
 * Description : Insertion sort
 * Remarks     : Worst : O(nˆ2) Best : O(n)
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

// Function for inserion sort.
void insertion_sort(int *arr, int n) {
    int val, index;

    for(int i = 1; i < n; ++i) {
        val = arr[i];
        index = i-1;

        while(index >= 0 && arr[index] > val) {
            arr[index+1] = arr[index];
            --index;
        }
        arr[index+1] = val;
    }
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    insertion_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}