#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescription(){
    int arr[] = { 5, 3, 7, 9, 4, 6, 1, 0, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, N);
    cout << "Sorted array: \n";
    int i;
    for (i = 0; i < N; i++)
        cout << " " << arr[i];
}