#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int Source;
    int Destination;
    int Weight;
    struct Edge* next;
};

struct Graph {
    int numVertices;
    int numEdges;
    struct Edge* edges[100];
};

struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* Graph = (struct Graph*)malloc(sizeof(struct Graph));
    Graph->numVertices = numVertices;
    Graph->numEdges = numEdges;

    for(int i = 0; i < numVertices; i++) {
        Graph->edges[i] = NULL;
    }
    return Graph;
}

void AddEdge(struct Graph* graph, int source, int destination, int weight) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->Source = source;
    edge->Destination = destination;
    edge->Weight = weight;
    edge->next = graph->edges[source];
    graph->edges[source] = edge;
}

void printGraph(struct Graph* graph) {
    printf("Edges in the Graph:\n");
    for(int i = 0; i < graph->numVertices; i++) {
        struct Edge* edge = graph->edges[i];
        while (edge != NULL) {
            printf("Source: %d | Destination: %d | Weight: %d\n", edge->Source, edge->Destination, edge->Weight);
            edge = edge->next;
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void FloydWarshall(struct Graph* graph) {
    int size = graph->numVertices;
    int D[size][size];

    // Initialize distance matrix with infinity
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            D[i][j] = INF;
        }
    }

    // Initialize distance matrix with direct edges' weights
    for(int i = 0; i < size; i++) {
        struct Edge* edge = graph->edges[i];
        while(edge != NULL) {
            D[edge->Source][edge->Destination] = edge->Weight;
            edge = edge->next;
        }
    }

    // Set diagonal elements to zero
    for(int i = 0; i < size; i++) {
        D[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for(int k = 0; k < size; k++) {
        // Print intermediate matrix
        printf("\nIntermediate matrix after iteration %d:\n", k + 1);
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if (D[i][j] == INF) {
                    printf("INF\t");
                } else {
                    printf("%d\t", D[i][j]);
                }
            }
            printf("\n");
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if (D[i][k] != INF && D[k][j] != INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    // Print the final distances
    printf("\nShortest distances between vertices:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (D[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Graph* graph = createGraph(numVertices, numEdges);

    // Add edges to the graph
    printf("Enter source, destination, and weight for each edge:\n");
    for(int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        AddEdge(graph, source, destination, weight);
    }

    // Print Graph
    printGraph(graph);

    // Run Floyd-Warshall Algorithm
    FloydWarshall(graph);

    return 0;
}
