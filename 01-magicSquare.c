#include <stdio.h>

#define SIZE 5
int A[SIZE][SIZE];
int N = SIZE;

printArray(int rowSumFlag, int colSumFlag)
{
    int sumRow = 0;
    int sumCol[SIZE] = {0};
    int sumDiag = 0;
    int i, j;
    printf("Column ");
    for (i = 0; i < N; i++) { // Print an array
        printf("[%02d]",i);
    }
    printf("\n");

    for (i = 0; i < N; i++) { // Print an array
        printf("row[%d] ", i);
        for(j = 0; j < N; j++) {
            printf(" %02d ", A[i][j]);
            sumRow += A[i][j];
            sumCol[j] += A[i][j]; 
            if (i == j) 
                sumDiag += A[i][j];
        }

        if (rowSumFlag) {
            printf("| %d", sumRow);
        }
        printf("\n");
        sumRow = 0;
    }

    if (colSumFlag) {
        printf("       ");
        for (i = 0; i < N; i++) { // Print an array
            printf(" %02d ",sumCol[i]);
        }
        printf("| %02d\n", sumDiag);
    }
    printf("\n");
}

int
main(void)
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

    printArray(1, 1);

    return 0;
}
