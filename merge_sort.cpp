/*
 * Author      : Midhun P
 * Description : Merge sort with O(1) space complexity
 * Remarks     : Worst : O(n*log(n)) Best : O(n*log(n))
 */

#include <iostream>

using namespace std;

void print_array(int *arr, int n) {
    for(int i = 0; i < n; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b " << endl;
}

void merge_without_space(int *arr, int start, int mid, int end) {
    int seg2_start = mid+1;
    
    while(start <= mid && seg2_start <= end) {
        if(arr[start] <= arr[seg2_start])
            ++start;
        else {
            int val = arr[seg2_start];
            int i = seg2_start;

            while(i > start) {
                arr[i] = arr[i-1];
                --i;
            }
            arr[i] = val;
            ++start;
            ++mid;
            ++seg2_start;    
        }
    }
}

void merge_with_space(int *arr, int start, int mid, int end) {
    int a1_n = mid - start + 1;
    int a2_n = end - mid;

    int* a1 = (int*) malloc(sizeof(int) * a1_n);
    int* a2 = (int*) malloc(sizeof(int) * a2_n);

    for(int index = 0, i = start; i <= mid; ++i)
        a1[index++] = arr[i];

    for(int index = 0, i = mid+1; i <= end; ++i)
        a2[index++] = arr[i];

    int i = 0, j = 0;
    while(i < a1_n && j < a2_n) {
        if(a1[i] < a2[j])
            arr[start++] = a1[i++];
        else
            arr[start++] = a2[j++];
    }

    while(i < a1_n)
        arr[start++] = a1[i++];

    while(j < a2_n)
        arr[start++] = a2[j++];

    free(a1);
    free(a2);
}

// Function for merge sort.
void merge_sort_util(int *arr, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        merge_sort_util(arr, start, mid);
        merge_sort_util(arr, mid+1, end);
        merge_with_space(arr, start, mid, end);
    }
}

void merge_sort(int *arr, int n) {
    merge_sort_util(arr, 0, n-1);
}

int main() {
    int n = 10;
    int arr[] = {15, 16, 8, 5, 6, 30, 25, 17, 45, 4};

    cout << "Before : ";
    print_array(arr, n);

    merge_sort(arr, n);

    cout << "After  : ";
    print_array(arr, n);

    return 0;
}