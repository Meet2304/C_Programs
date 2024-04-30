#include<stdio.h>

void merge(int Arr[], int lb, int mid, int ub)
{
    int i, j, k, temp[100];
    i = lb;
    j = mid+1;
    k = lb;

    while(i <= mid && j<=ub)
    {
        if(Arr[i] <= Arr[j])
        {
            temp[k] = Arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = Arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        temp[k] = Arr[i];
        i++;
        k++;
    }
    
    while(j <= ub)
    {
        temp[k] = Arr[j];
        j++;
        k++;
    }

    for(k=lb ; k<=ub ; k++)
    {
        Arr[k] = temp[k];
    }
}

void mergeSort(int Arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid = (lb + ub)/2;
        mergeSort(Arr, lb, mid);
        mergeSort(Arr, mid+1, ub);
        merge(Arr, lb, mid, ub);
    }
    
}

int main()
{
    int arr[100], length;
    printf("Enter length of the array: ");
    scanf("%d", &length);

    for(int i=0 ; i<length ; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, length-1);

    for(int i=0 ; i<length ; i++)
    {
        printf("%d ", arr[i]);
    }
}