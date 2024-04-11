#include <stdio.h>
#include <stdbool.h>

#define N 100

int Board[N][N];

// struct Queen
// {
//     int Xcord;
//     int Ycord;
// };

// Function to check if it's safe to place a queen at position (x, y)
int CheckSafe(int x, int y, int size)
{
    // Check column
    for (int i = 0; i < y; i++) {
        if (Board[x][i])
            return 0;
    }

    // Check upper diagonal on left side
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (Board[i][j])
            return 0;
    }

    // Check lower diagonal on left side
    for (int i = x, j = y; j >= 0 && i < size; i++, j--) {
        if (Board[i][j])
            return 0;
    }

    // It's safe to place a queen at this position
    return 1;
}

// Recursive function to solve N Queens problem
bool solveNQueens(int col, int n) {
    // If all queens are placed then return true
    if (col >= n)
        return true;

    // Try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        // Check if the queen can be placed on board[i][col]
        if (CheckSafe(i, col, n)) {
            // Place the queen
            Board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(col + 1, n))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution then backtrack
            Board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to print the solution
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", Board[i][j]);
        printf("\n");
    }
}

int main() {
    int numQueens;
    printf("Enter the number of Queens: ");
    scanf("%d", &numQueens);

    if (numQueens <= 0 || numQueens > N) {
        printf("Invalid input!\n");
        return 1;
    }

    // Initialize the board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Board[i][j] = 0;

    if (solveNQueens(0, numQueens))
        printSolution(numQueens);
    else
        printf("Solution does not exist");

    return 0;
}
