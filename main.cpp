#include <iostream>

#include "cppBasis.cpp"
#include "2sorting/bubbleSort.cpp"
#include "2sorting/insertionSort.cpp"
#include "2sorting/selectionSort.cpp"
#include "2sorting/utilities.cpp"
using namespace std;

int main(){
    int arr[] = { 5, 3, 7, 9, 4, 6, 1, 0, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}