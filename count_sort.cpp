/*
 * Author      : Midhun P
 * Description : Count sort
 * Remarks     : Worst: O(n) Best: O(n)
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

// Function for count sort.
void count_sort(int *arr, int n) {
    int *res, *count;

    res = (int *) malloc(n * sizeof(int));
    count = (int *) calloc(10, sizeof(int));

    // Count it
    for (int i = 0; i < n; ++i)
        ++count[arr[i]%10];

    // Cumulative sum
    for(int i = 1; i < 10; ++i)
        count[i] += count[i-1];

    // Place elements in the order
    for(int i = n-1; i >= 0; --i)
        res[--count[arr[i] % 10]] = arr[i];

    // Copy to the output
    for (int i = 0; i < n; ++i)
        arr[i] = res[i];

    free(res);
    free(count);
}

int main() {
    int n = 10;
    int arr[] = {5, 0, 8, 7, 6, 1, 5, 3, 9, 4};

    cout << "Before : ";
    print_array(arr, n);

    count_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}