#include<stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(int arr[], int len)
{
    for(int i=0 ; i<len-1 ; i++)
    {
        int min_index = i;
        for(int j=i+1 ; j<len ; j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main()
{
    int length, arr[100];
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    for(int i=0 ; i<length ; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, length);

    printf("Sorted Array: ");
    for(int i=0 ; i<length ; i++)
    {
        printf("%d ", arr[i]);
    }
}