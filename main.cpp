#include <iostream>

#include "cppBasis.cpp"
#include "2sorting/bubbleSort.cpp"
#include "2sorting/insertionSort.cpp"
#include "2sorting/selectionSort.cpp"
#include "2sorting/mergeSort.cpp"
#include "2sorting/quickSort.cpp"
#include "2sorting/utilities.cpp"
#include "0algorithm/binarySearch.cpp"
#include "0algorithm/localPeak.cpp"
using namespace std;

int main(){
    int arr[] = { 5, 3, 7, 9, 4, 6, 1, 0, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);
    // quickSort(arr, 0, N-1);

    int i = findLocalPeak(arr, 0, N-1);
    cout << i;
    // cout << "Sorted array: \n";
    // printArray(arr, N);
    return 0;
}