/*
 * Author      : Midhun P
 * Description : Radix sort
 * Remarks     : Worst: O(n) Best: O(n)
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

int find_max(int *arr, int n) {
    int max = arr[0];

    for (int i = 1; i < n; ++i)
        if(max < arr[i])
            max = arr[i];
    
    return max;
}

// Function for count sort.
void count_sort(int *arr, int n, int exp) {
    int *res, *count;

    res = (int *) malloc(n * sizeof(int));
    count = (int *) calloc(10, sizeof(int));

    // Count it
    for (int i = 0; i < n; ++i)
        ++count[(arr[i] / exp) % 10];

    // Cumulative sum
    for(int i = 1; i < 10; ++i)
        count[i] += count[i-1];

    // Place elements in the order
    for(int i = n-1; i >= 0; --i)
        res[--count[(arr[i] / exp) % 10]] = arr[i];

    // Copy to the output
    for (int i = 0; i < n; ++i)
        arr[i] = res[i];

    free(res);
    free(count);
}

// Function to do radix sort.
void radix_sort(int *arr, int n) {
    int max = find_max(arr, n);

    for(int exp = 1; max/exp; exp*=10) 
        count_sort(arr, n, exp);
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    radix_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}