#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {break;}
    }
}

void bubbleSortDescription(){
    int arr[] = { 5, 3, 7, 9, 4, 6, 1, 0, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    int i;
    for (i = 0; i < N; i++)
        cout << " " << arr[i];
}