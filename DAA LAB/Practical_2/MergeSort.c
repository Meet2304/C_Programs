#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb;
    int SortArr[100];
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            SortArr[k] = arr[i];
            i++;
        } else {
            SortArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        SortArr[k] = arr[i];
        k++;
        i++;
    }

    while (j <= ub) {
        SortArr[k] = arr[j];
        k++;
        j++;
    }

    for (k = lb; k <= ub; k++) {
        arr[k] = SortArr[k];
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void main() {
    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    printf("Initial Array: \n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSorted Array: \n");
    mergeSort(arr, 0, 8);
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
}
