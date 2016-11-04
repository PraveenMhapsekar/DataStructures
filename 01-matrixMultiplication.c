#include <stdio.h>

#define SIZE 4
//int A[SIZE][SIZE];
int N = SIZE;

priintArray(int A[SIZE][SIZE], int rowSumFlag, int colSumFlag, int d)
{
    int sumRow = 0;
    int sumCol[SIZE] = {0};
    int sumDiag = 0;
    int i, j;
    printf("Column ");
    for (i = 0; i < N; i++) { // Print an array
        printf("[%0*d]", d, i);
    }
    printf("\n");

    for (i = 0; i < N; i++) { // Print an array
        printf("row[%d] ", i);
        for(j = 0; j < N; j++) {
            printf(" %0*d ", d,  A[i][j]);
            sumRow += A[i][j];
            sumCol[j] += A[i][j]; 
            if (i == j) 
                sumDiag += A[i][j];
        }

        if (rowSumFlag) {
            printf("| %*d", d, sumRow);
        }
        printf("\n");
        sumRow = 0;
    }

    if (colSumFlag) {
        printf("       ");
        for (i = 0; i < N; i++) { // Print an array
            printf(" %0*d ", d+1, sumCol[i]);
        }
        printf("| %0*d\n", d+1, sumDiag);
    }
    printf("\n");
}

magicSquare(int A[SIZE][SIZE])
{
    int i, j, row, col;
    int count = 0;

    i = 0;
    j = (N - 1)/2;

    A[i][j] = 1;   // start with first row and mid column

    for (count = 2; count <= N*N; count++) {
       row = (i - 1) < 0 ? N - 1 : i - 1;  // Decrease row
       col = (j - 1) < 0 ? N - 1 : j - 1;  // decrease column

        if (A[row][col]) {   // If it is already occupied
            i = (++i) % N;   // Move to next down row
        } else {
            i = row;
            j = col;
        }
        A[i][j] = count;   // Store count
    }
}

void
clearMatrix(int A[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < N; i++)  // Print an array
        for(j = 0; j < N; j++) 
            A[i][j] = 0;
}

matrixMultiplication(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
    int i, j, k;

    for (i = 0; i < N; i++)  // Print an array
        for(j = 0; j < N; j++) { 
            C[i][j] = 0;
            for(k = 0; k < N; k++) 
                C[i][j] += A[i][k] * B[k][j];
        }
}

int
main(void)
{
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE];
    clearMatrix(A);
    clearMatrix(B);
    clearMatrix(C);

    magicSquare(A);
    printArray(A, 0, 0, 2);

    magicSquare(B);
    printArray(B, 0, 0, 2);

    matrixMultiplication(A, B, C);
    printArray(C, 0, 0, 4);

    return 0;
}
