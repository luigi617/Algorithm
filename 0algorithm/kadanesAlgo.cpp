#include <limits.h>
#include <algorithm>
using namespace std;

int kadanesAlgo(int arr[]){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<n; i++){
        max_ending_here += arr[i];
        max_so_far = max(max_so_far, max_ending_here);
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}