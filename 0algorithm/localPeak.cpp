#include <iostream>
using namespace std;

int findLocalPeak(int arr[], int l, int r) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        bool isLeftSmaller = (m == l) || (arr[m-1] <= arr[m]);
        bool isRightSmaller = (m == r) || (arr[m+1] <= arr[m]);
        if (isLeftSmaller && isRightSmaller) {
            return m; 
        }
        
        if (m < r && arr[m+1] > arr[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1; 
}