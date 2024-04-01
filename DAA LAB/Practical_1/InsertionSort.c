#include<stdio.h>

Insertionsort(int arr[], int len)
{
    int i;
    for(i=1; i<len ; i++)
    {
        int pivot = arr[i];
        int j = i-1;
         while( j>=0 && pivot < arr[j])
         {
             arr[j+1] = arr[j];
             j--;
         }
         arr[j+1] = pivot;
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
    Insertionsort(arr, len);

    for(i = 0 ; i< sizeof(arr)/sizeof(arr[0]) ; i++)
    {
        printf("%d " ,arr[i]);
    }
}

