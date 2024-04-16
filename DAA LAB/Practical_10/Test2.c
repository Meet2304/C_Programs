#include <stdio.h>

// Function to find the peak entry in a unimodal array
int findPeak(int A[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // If mid is greater than its neighbors, it's a peak
        if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
            return mid;
        }
        // If mid is less than its right neighbor, peak lies on the right
        else if (A[mid] < A[mid + 1]) {
            low = mid + 1;
        }
        // If mid is less than its left neighbor, peak lies on the left
        else {
            high = mid;
        }
    }
    
    // If low and high converge, we have found the peak
    return low;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    int peak = findPeak(A, n);
    
    printf("Peak entry is at index: %d having value: %d\n", peak, A[peak]);
    
    return 0;
}
