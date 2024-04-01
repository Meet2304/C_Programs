#include <stdio.h>
#include <time.h>

void multiply(int size, int First[][size], int Second[][size], int Result[][size])
{
  // Base case: If matrices are 1x1, perform single multiplication
  if (size == 1)
  {
    Result[0][0] = First[0][0] * Second[0][0];
    return;
  }

  // Divide matrices into sub-matrices
  int half_size = size / 2;

  int a11[half_size][half_size], a12[half_size][half_size], a21[half_size][half_size], a22[half_size][half_size];
  int b11[half_size][half_size], b12[half_size][half_size], b21[half_size][half_size], b22[half_size][half_size];
  int c1111[half_size][half_size], c1221[half_size][half_size], c1112[half_size][half_size], c1222[half_size][half_size], c2111[half_size][half_size], c2221[half_size][half_size], c2112[half_size][half_size], c2222[half_size][half_size];

  for (int i = 0; i < half_size; i++)
  {
    for (int j = 0; j < half_size; j++)
    {
      a11[i][j] = First[i][j];
      a12[i][j] = First[i][j + half_size];
      a21[i][j] = First[i + half_size][j];
      a22[i][j] = First[i + half_size][j + half_size];

      b11[i][j] = Second[i][j];
      b12[i][j] = Second[i][j + half_size];
      b21[i][j] = Second[i + half_size][j];
      b22[i][j] = Second[i + half_size][j + half_size];
    }
  }

  // Recursive calls for sub-matrices
  multiply(half_size, a11, b11, c1111);
  multiply(half_size, a12, b21, c1221);
  multiply(half_size, a11, b12, c1112);
  multiply(half_size, a12, b22, c1222);
  multiply(half_size, a21, b11, c2111);
  multiply(half_size, a22, b21, c2221);
  multiply(half_size, a21, b12, c2112);
  multiply(half_size, a22, b22, c2222);

  // Combine results back into the original matrix
  for (int i = 0; i < half_size; i++) {
    for (int j = 0; j < half_size; j++) {
      Result[i][j] = c1111[i][j] + c1221[i][j];
      Result[i][j + half_size] = c1112[i][j] + c1222[i][j];
      Result[i + half_size][j] = c2111[i][j] + c2221[i][j];
      Result[i + half_size][j + half_size] = c2112[i][j] + c2222[i][j];
    }
  }
}

void printMatrix(int n, int matrix[][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}



int main()
{
  int size;
  printf("Enter the size of the matrices(of order 2): ");
  scanf("%d", &size);

  int A[size][size], B[size][size], C[size][size];

  printf("Enter elements for First Matrix :\n");
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter elements for Second Matrix :\n");
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      scanf("%d", &B[i][j]);
    }
  }

  multiply(size, A, B, C);

   printf("Product of First and Second Matrix:\n");
   printf("Resultant Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

  return 0;
}
