#include <stdio.h>


#define TRUE  1
#define FALSE 0

#define N     8

int B[N][N]; /* board */

void
printBoard()
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fprintf(stderr, "%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void
clearBoard()
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) 
            B[i][j] = 0;
}

int
checkRow(int r)
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == r) {
                if (B[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int
checkDiagonal(int r, int c)
{
#if 0    
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == r) {
                if (B[i][j]) {
                    return 1;

                }
            }
        }
    }
#endif
    return 0;
}

void
placeQueens(int r, int c) 
{
    int qCount = 0;

    if (B[r][c]) {
        return;
    } else {
        B[r][c] = 1;
        qCount++;
        c = (c + 1) % N;
    }

    while (qCount < N) {
        if (checkRow(r) || checkDiagonal(r, c)) {
            r = (r + 1) % N;
            continue;
        } else {
            B[r][c] = 1;
            qCount++;
            c = (c + 1) % N;
        }
    }
}


int
main(void)
{
    clearBoard();
    printBoard();
    placeQueens(3, 0);
    printBoard();
    return 0;
}

