#include<stdio.h>
#include<stdlib.h>

struct EDGE
{
    int Source, Dest, Weight;
};

struct SUBSET
{
    int parent;
};

int Find(struct SUBSET subsets[], int i)
{
    if(subsets[i].parent != i)
    {
        subsets[i].parent = Find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

int Union(struct SUBSET subsets[], int x, int y)
{
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);

    subsets[xroot].parent = yroot;
}

void Kruskal(struct EDGE edges[], int V, int E)
{
    struct EDGE MST[V];
    struct SUBSET subsets[V];

    for(int i=0 ; i<E ; i++)
    {
        subsets[i].parent = i;
    }

    for(int i=0 ; i<E ; i++)
    {
        for(int j=i+1 ; j<E ; j++)
        {
            if(edges[i].Weight>edges[j].Weight)
            {
                struct EDGE temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int e=0, i=0;

    while(e<V-1 && i<E)
    {
        struct EDGE nextEdge = edges[i++];

        int x = Find(subsets, nextEdge.Source);
        int y = Find(subsets, nextEdge.Dest);

        if(x != y)
        {
            MST[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    for(int i=0 ; i<e ; i++)
    {
        printf("%d - %d: %d\n", MST[i].Source, MST[i].Dest, MST[i].Weight);
    }

}

int main()
{
    int V = 4;
    int E = 5;
    struct EDGE edges[] = {{0, 1, 10}, {0, 2, 6}, {2, 3, 4}, {3, 1, 15}, {0, 3, 5}};
    Kruskal(edges, V, E);
    return 0;
}