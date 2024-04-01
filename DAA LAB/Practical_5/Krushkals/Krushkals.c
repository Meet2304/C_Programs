#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
    char Source[100];
    char Dest[100];
    int Weight;
};

struct Graph
{
    int V;
    int E;
    struct Edge *Edges;
};

struct Subset
{
    int Parent[100];
};

// Function to find root of a node with path compression
int Find(struct Subset subsets[], int i)
{
    if (subsets[i].Parent[0] != i)
    {
        subsets[i].Parent[0] = Find(subsets, subsets[i].Parent[0]);
    }
    return subsets[i].Parent[0];
}

// Function for Union of two nodes
void Union(struct Subset subsets[], int A, int B)
{
    int xroot = Find(subsets, A);
    int yroot = Find(subsets, B);

    // Ensure not to create a cycle
    if (xroot != yroot)
    {
        subsets[xroot].Parent[0] = yroot;
    }
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V - 1]; // To store the result MST
    int e = 0;                 // Index to result[] array

    // Step 1: Sort all the edges in non-decreasing order of their weight
    for (int i = 0; i < graph->E; i++)
    {
        for (int j = i + 1; j < graph->E; j++)
        {
            if (graph->Edges[i].Weight > graph->Edges[j].Weight)
            {
                // Swap edges if they are in the wrong order
                struct Edge temp = graph->Edges[i];
                graph->Edges[i] = graph->Edges[j];
                graph->Edges[j] = temp;
            }
        }
    }

    // Allocate memory for subsets
    struct Subset subsets[V];
    for (int i = 0; i < V; i++)
    {
        subsets[i].Parent[0] = i;
    }

    // Step 2: Iterate through all the sorted edges
    for (int i = 0; e < V - 1 && i < graph->E; i++)
    {
        struct Edge next_edge = graph->Edges[i];

        int x = Find(subsets, next_edge.Source[0] - '0'); // Convert char to int
        int y = Find(subsets, next_edge.Dest[0] - '0');   // Convert char to int

        // Include the edge in the result if including it doesn't form a cycle
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++)
    {
        printf("%s - %s (%d)\n", result[i].Source, result[i].Dest, result[i].Weight);
    }
}

int main()
{
    // Example usage
    struct Graph graph;
    printf("Enter the number of vertices: ");
    scanf("%d", &graph.V);

    printf("Enter the number of edges: ");
    scanf("%d", &graph.E);

    graph.Edges = (struct Edge *)malloc(graph.E * sizeof(struct Edge));

    // Initialize edges from user input
    for (int i = 0; i < graph.E; i++)
    {
        printf("Enter source, destination, and weight for edge %d (separated by spaces): ", i + 1);
        scanf("%s %s %d", graph.Edges[i].Source, graph.Edges[i].Dest, &graph.Edges[i].Weight);
    }

    KruskalMST(&graph);

    free(graph.Edges); // Free allocated memory

    return 0;
}
