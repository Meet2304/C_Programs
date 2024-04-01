#include<stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int Partition(int arr[], int lb, int ub)
{
    int pivot = arr[ub];
    int i = lb-1;

    for(int j = lb; j<=ub; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[ub]);
    return i+1;
}

void QuickSort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int p = Partition(arr, lb, ub);
        QuickSort(arr, lb, p-1);
        QuickSort(arr, p+1, ub);
    }
}

void main()
{
   int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
   int n = sizeof(arr)/sizeof(arr[0]);
    printf("Initial Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    QuickSort(arr, 0, n-1);
    printf("\nSorted Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
