#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

# define INF INT_MAX

struct EDGE
{
    int Source;
    int Destination;
    int Weight;
    struct EDGE* next;
};

struct GRAPH
{
    int numVertices;
    int numEdges;
    struct EDGE* edges[100];
};

struct GRAPH* CreateGraph(int V, int E)
{
    struct GRAPH* graph = (struct GRAPH*)malloc(sizeof(struct GRAPH));
    graph->numVertices = V;
    graph->numEdges = E;
    for(int i=0 ; i<E ; i++)
    {
        graph->edges[i] = NULL;
    }
    return graph;
}

void AddEdge(struct GRAPH* graph, int src, int dest, int wght)
{
    struct EDGE* newedge = (struct EDGE*)malloc(sizeof(struct EDGE));
    newedge->Source = src;
    newedge->Destination = dest;
    newedge->Weight = wght;
    newedge->next = graph->edges[src];
    graph->edges[src] = newedge;
}

void PrintGraph(struct GRAPH* Graph)
{
    printf("EDGES IN GRAPH: \n");
    for(int i=0 ; i<Graph->numEdges ; i++)
    {
        struct EDGE* edge = Graph->edges[i];
        printf("SOURCE: %d | DESTINATION: %d | WEIGHT: %d \n", edge->Source, edge->Destination, edge->Weight);
        edge = edge->next;
    }
}

int min(int a, int b)
{
    return (a<b) ? a : b;
}

void FloydWarshall(struct GRAPH* Graph)
{
    int size = Graph->numVertices;
    int D[size][size];

    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            D[i][j] = INF;
        }
    }

    for(int i=0 ; i<size ; i++)
    {
        struct EDGE* edge = Graph->edges[i];
        while(edge!=NULL)
        {
            D[edge->Source][edge->Destination] = edge->Weight;
            edge = edge->next;
        }
    }

    for(int i=0 ; i<size ; i++)
    {
        D[i][i] = 0;
    }

    for(int k=0 ; k<size ; k++)
    {
        for(int i=0 ; i<size ; i++)
        {
            for(int j=0 ; j<size ; j++)
            {
                if(D[i][k]!=INF && D[k][j]!= INF)
                {
                    D[i][j] = min( D[i][j] , D[i][k] + D[k][j]);
                }
            }
        }
    }

    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            if(D[i][j]==INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int vert, edges;
    printf("Enter the number of Vertices: ");
    scanf("%d", &vert);
    printf("Enter the number of Edges: ");
    scanf("%d", &edges);

    struct GRAPH* Graph = CreateGraph(vert, edges);

    for(int i=0 ; i<edges ; i++)
    {
        int src, dest, wght;
        printf("Enter the Source, Destination and Weight of the Edge:");
        scanf("%d %d %d", src, dest, wght);
        AddEdge(Graph, src, dest, wght);
    }

    PrintGraph(Graph);

    FloydWarshall(Graph);
}