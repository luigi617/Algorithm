void merge(int array[], int left, int mid, int right)
{
    int subArray1 = mid - left + 1;
    int subArray2 = right - mid;

    int leftArray[subArray1];
    int rightArray[subArray2];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArray1; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArray2; j++)
        rightArray[j] = array[mid + 1 + j];

    int subArr1Index = 0, subArr2Index = 0;
    int subMergedArrIndex = left;

    while (subArr1Index < subArray1 && subArr2Index < subArray2) {
        if (leftArray[subArr1Index] <= rightArray[subArr2Index]) {
            array[subMergedArrIndex] = leftArray[subArr1Index];
            subArr1Index++;
        }
        else {
            array[subMergedArrIndex] = rightArray[subArr2Index];
            subArr2Index++;
        }
        subMergedArrIndex++;
    }

    
    while (subArr1Index < subArray1) {
        array[subMergedArrIndex] = leftArray[subArr1Index];
        subArr1Index++;
        subMergedArrIndex++;
    }
    while (subArr2Index < subArray2) {
        array[subMergedArrIndex] = rightArray[subArr2Index];
        subArr2Index++;
        subMergedArrIndex++;
    }
}


void mergeSort(int array[], int begin, int end) {
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}