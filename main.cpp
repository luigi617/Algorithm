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
#include "6unionFind/quickUnion.hpp"
using namespace std;

int main(){
    QuickUnion* q = new QuickUnion(10);
    q->union_(3, 4);
    q->union_(4, 9);
    q->union_(8, 0);
    q->union_(2, 3);
    q->union_(5, 6);
    q->union_(5, 9);
    q->union_(7, 3);
    q->union_(4, 8);
    q->union_(6, 1);
    q->print();
    
    return 0;
}