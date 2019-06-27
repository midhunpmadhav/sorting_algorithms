/*
 * Author      : Midhun P
 * Description : Quick sort
 * Remarks     : Worst : O(n*log(n)) Best : O(n*log(n))
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

// Function for quick sort.
void quick_sort_util(int *arr, int start, int end) {
    if(start < end) {
        int pivot = arr[start];
        int i = start + 1; 
        int j = end;

        while(i < j) {
            while(arr[i] < pivot)
                ++i;
            while(arr[j] > pivot)
                --j;

            if(i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[start]);

        quick_sort_util(arr, start, j-1);
        quick_sort_util(arr, j+1, end);
    }
}

void quick_sort(int *arr, int n) {
    quick_sort_util(arr, 0, n-1);
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    quick_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}