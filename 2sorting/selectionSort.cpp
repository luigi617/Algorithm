#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
  
    for (i = 0; i < n - 1; i++) { 
  
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 
  
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]); 
        }
    } 
} 

void selectionSortDescription(){
    int arr[] = { 5, 3, 7, 9, 4, 6, 1, 0, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, N);
    cout << "Sorted array: \n";
    int i;
    for (i = 0; i < N; i++)
        cout << " " << arr[i];
}