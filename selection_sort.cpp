/*
 * Author      : Midhun P
 * Description : Selection sort
 * Remarks     : Worst: O(n^2) Best: O(n^2)
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

// Function for selection sort.
void selection_sort(int *arr, int n) {
    for(int min, i = 0; i < n - 1; ++i) {
        min = i;
        
        for(int j = i+1; j < n; ++j)
            if(arr[j] < arr[min])
                min = j;
        
        if(min != i)
            swap(arr[i], arr[min]);
    }
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    selection_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}