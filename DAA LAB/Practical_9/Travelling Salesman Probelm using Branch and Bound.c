#include <stdio.h>
#include <limits.h>

#define N 10 // Maximum number of cities

int n; // Number of cities
int graph[N][N]; // Graph representing distances between cities
int minCost = INT_MAX; // Variable to store the minimum cost of the tour
int finalPath[N]; // Array to store the final path

// Function to calculate the lower bound cost of a partial tour using a greedy approach
int calculateLB(int path[], int level, int visited[]) {
    // Greedy approach: return the sum of minimum remaining edges from each unvisited city
    int lb = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minDist = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && graph[i][j] < minDist) {
                    minDist = graph[i][j];
                }
            }
            lb += minDist;
        }
    }
    return lb;
}

// Function to find the minimum cost using branch and bound
void tsp(int level, int cost, int path[], int visited[]) {
    // Base case: if all cities are visited
    if (level == n) {
        // Check if there's a path back to the starting city
        if (graph[path[level - 1]][0] != 0) {
            int totalCost = cost + graph[path[level - 1]][0]; // Total cost of the tour
            // Update minimum cost if this tour is better
            if (totalCost < minCost) {
                minCost = totalCost;
                for (int i = 0; i < n; i++) {
                    finalPath[i] = path[i];
                }
            }
        }
        return;
    }

    // Explore child nodes (unvisited cities)
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[path[level - 1]][i] != 0) {
            visited[i] = 1; // Mark city i as visited
            path[level] = i; // Add city i to the current path
            int lowerBound = calculateLB(path, level, visited);
            if (cost + graph[path[level - 1]][i] + lowerBound < minCost) {
                tsp(level + 1, cost + graph[path[level - 1]][i], path, visited); // Recur for city i
            }
            visited[i] = 0; // Mark city i as unvisited after exploring all paths from it
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distances between the cities in the format 'source city, destination city, distance':\n");
    printf("For example, if there are 3 cities, and the distances are: \n");
    printf("0 1 10 (meaning distance from city 0 to city 1 is 10)\n");
    printf("You should enter the distances as above:\n");

    int source, destination, distance;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        scanf("%d %d %d", &source, &destination, &distance);
        graph[source][destination] = distance;
        graph[destination][source] = distance; // Assuming distance from A to B is same as B to A
    }

    // Start with the first city (0)
    int path[N], visited[N] = {0};
    path[0] = 0;
    visited[0] = 1;

    // Solve TSP using branch and bound
    tsp(1, 0, path, visited);

    // Output the minimum cost and the corresponding path
    printf("The minimum cost of the tour is: %d\n", minCost);
    printf("The tour path is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", finalPath[i]);
    }
    printf("%d\n", finalPath[0]); // Return to the starting city

    return 0;
}
