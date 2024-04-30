#include<stdio.h>

struct ITEM
{
    int weight, profit;
};

struct ITEM Items[100];

void Sort(struct ITEM items[], int Itemcount)
{
    for(int i=0 ; i<Itemcount ; i++)
    {
        for( int j=i+1 ; j<Itemcount ; j++)
        {
            if((items[i].profit/items[i].weight)<(items[j].profit/items[j].weight))
            {
                struct ITEM temp;
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

double FractionalKnapsack(struct ITEM items[], int itemCount, int MaxWeight)
{
    Sort(items, itemCount);
    double FinalProfit = 0.0;
    struct ITEM SelectedItems[100];

    for(int i=0 ; i<itemCount ; i++)
    {
        if(items[i].weight<MaxWeight)
        {
            MaxWeight -= items[i].weight;
            FinalProfit += items[i].profit;
            SelectedItems[i].profit = items[i].profit;
            SelectedItems[i].weight = items[i].weight;
        }

        else
        {
            FinalProfit += (double)items[i].profit * ((double)MaxWeight / items[i].weight);
            SelectedItems[i].profit = items[i].profit;
            SelectedItems[i].weight = items[i].weight;
            break;
        }
    }
    return FinalProfit;
    //return SelectedItems;
}

int main()
{
    int itemCount, MaxWeight;
    struct ITEM items[100];
    printf("Enter the total number of items: ");
    scanf("%d", &itemCount);

    printf("Enter the Maximum Weight of Knapsack: ");
    scanf("%d", &MaxWeight);
    
    for(int i=0 ; i<itemCount ; i++)
    {
        printf("Enter the weight and proft of the item: ");
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }

    printf("%lf", FractionalKnapsack(items, itemCount, MaxWeight));

    // printf("SELECTED ITEMS: ");
    // for(int i=0 ; i<itemCount ; i++)
    // {
    //     printf("%d %d", Sel[i].weight, items[i].profit);
    // }
}

