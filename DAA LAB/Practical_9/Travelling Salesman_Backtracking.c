/*
TESTCASE:
0 1 10
0 2 15
0 3 20
1 2 35
1 3 25
2 3 30
The minimum cost of the tour is: 80
The tour path is: 0 2 3 1 0
*/

#include <stdio.h>
#include <limits.h>

#define MAX_N 10 // Maximum number of cities
#define INF INT_MAX // Infinity

int N; // Number of cities
int graph[MAX_N][MAX_N]; // Adjacency matrix to represent the distances between cities
int visited[MAX_N]; // Array to keep track of visited cities
int minCost; // Variable to store the minimum cost
int minPath[MAX_N]; // Array to store the path with minimum cost

// Recursive function to find the minimum cost of the Hamiltonian cycle
void TSP(int currentCity, int cost, int count, int path[]) {
    // If all cities are visited and there is a path back to the starting city
    if (count == N && graph[currentCity][0] != 0) {
        // Update the minimum cost if the current path's cost is less
        if (minCost > cost + graph[currentCity][0]) {
            minCost = cost + graph[currentCity][0];
            // Store the current path with minimum cost
            for (int i = 0; i < N; i++) {
                minPath[i] = path[i];
            }
        }
        return;
    }

    // Branch and Bound: Explore all possible paths from the current city
    for (int i = 0; i < N; i++) {
        // Check if city i has not been visited and there is a path to city i
        if (!visited[i] && graph[currentCity][i] != 0) {
            visited[i] = 1; // Mark city i as visited
            path[count] = i; // Add city i to the current path
            TSP(i, cost + graph[currentCity][i], count + 1, path); // Recur for city i
            visited[i] = 0; // Mark city i as unvisited after exploring all paths from it
        }
    }
}

int main() {
    // Prompt user to input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &N);

    // Prompt user to input the distances between cities
    printf("Enter the distances between cities in the form of source destination weight:\n");
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        graph[source][destination] = weight; // Input the distance into the adjacency matrix
        graph[destination][source] = weight; // Assuming distance from A to B is same as B to A
    }

    minCost = INF;
    visited[0] = 1; // Start from the first city
    int path[MAX_N];
    path[0] = 0; // Initialize the path with the starting city
    TSP(0, 0, 1, path); // Find the minimum cost using the Branch and Bound approach

    // Output the minimum cost and the corresponding path
    if (minCost == INF) {
        printf("No Hamiltonian cycle exists.\n");
    } else {
        printf("Minimum cost of the Hamiltonian cycle: %d\n", minCost);
        printf("Path: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", minPath[i]); // Print the cities in the path
        }
        printf("%d\n", minPath[0]); // Return to the starting city to complete the cycle
    }

    return 0;
}
