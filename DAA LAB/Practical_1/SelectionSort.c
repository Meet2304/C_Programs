#include<stdio.h>
#include<conio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void Selectionsort(int arr[], int len)
{
    int i, j;

    for(i = 0 ; i<len-1 ; i++)
    {
        int min_ind = i;
        for (j=i+1; j<len; j++)
            {
                if (arr[j]<arr[min_ind])
                {
                    min_ind = j;
                }
            }
        swap(&arr[min_ind], &arr[i]);
    }
}

void main()
{
    int i, arr[] = {7,4,10,8,3,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Initial Array: \n");
    for(i = 0 ; i< sizeof(arr)/sizeof(arr[0]) ; i++)
    {
        printf("%d " ,arr[i]);
    }

    printf("\n Sorted Array: \n");
    Selectionsort(arr, len);

    for(i = 0 ; i< sizeof(arr)/sizeof(arr[0]) ; i++)
    {
        printf("%d " ,arr[i]);
    }
}


