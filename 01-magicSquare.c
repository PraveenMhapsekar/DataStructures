#include <stdio.h>

#define SIZE 3
int A[SIZE][SIZE];
int N = SIZE;

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


    for (i = 0; i < N; i++) { // Print an array
        for(j = 0; j < N; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
                 
            

