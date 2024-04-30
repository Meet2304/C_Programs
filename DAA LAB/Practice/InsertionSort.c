#include<stdio.h>

void insertionSort(int arr[], int len)
{
    for(int i=1;i<len;i++)
    {
        int pivot = arr[i];
        int j = i-1;
        while(j>=0 && pivot<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pivot;
    }
}

int main()
{
    int length, arr[100];
    printf("Enter the length of the array:");
    scanf("%d", &length);

    for(int i=0 ; i<length ; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, length);

    for(int i=0 ; i<length ; i++)
    {
        printf("%d ", arr[i]);
    }
}