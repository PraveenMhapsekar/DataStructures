#include <stdio.h>

#define N 3

char A[N][N];

void 
clear ()
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = '0';
        }
    }
}

void 
display ()
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf ("%c ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int
checkValid (int row, int column) {
    if ((row > N-1) || (column > N-1)) 
        return 0;
    
    if ((row < 0) || (column < 0)) 
        return 0;
    
    if (A[row][column] == '0') 
        return 1;
    else 
        return 0;
}

int checkReverseDiag()
{
    int i;
    int j;
    char key = A[0][N-1];

    if (key == '0') {
        return 0;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((i+j) == (N-1)) {
                if (key != A[i][j]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int checkDiag()
{
    int i;
    int j;
    char key = A[0][0];

    if (key == '0') {
        return 0;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) {
                if (key != A[i][j]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int
checkWinner()
{
    int i;
    int j;

    // Check rows
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] == '0') {
                break;
             } else {
                 if (A[i][j] != A[i][(j+1)%(N-1)]) {
                     break;
                 }
                 if (j == N-1) {
                     printf ("Player %c is winner !!!\n", A[i][j]);
                     display();
                     return 1;
                 }
             }
        }
    }

    // Check Column
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] == '0') {
                break;
            } else {
                if (A[i][j] != A[(i+1)%(N-1)][j]) {
                     break;
                }
                if (i == N-1) {
                     printf ("Player %c is winner !!!\n", A[i][j]);
                     display();
                     return 1;
                }
             }
        }
    }

    if (checkDiag()) {
        printf ("Player %c is winner !!!\n", A[0][0]);
        display();
        return 1;
    }

    if (checkReverseDiag()) {
        printf ("Player %c is winner !!!\n", A[0][N-1]);
        display();
        return 1;
    }
    return 0;
}
int
isFull() 
{
    int i;
    int j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] == '0') {
                return 0;
            }
        }
    }
    return 1;
}

#define PLAYER (player == 0 ? 'X' : 'Y')
int
main(void) 
{  
    int player = 0;
    int r, c;

    clear();
    display();
    printf("Please enter value for row and column in the range of 0 - %d\n", N - 1);
    while (1) {
        while (1) { 
            printf("Player %c row?    :", PLAYER);
            if (scanf("%d", &r) == 1) {
                break;
            } else {
                __fpurge(stdin);
                printf("Please enter value for row and column in the range of 0 - %d\n", N - 1);
            } 
        }

        while (1) {
            printf("Player %c column? :", PLAYER);
            if (scanf("%d", &c) == 1) {
                break;
            } else {
                __fpurge(stdin);
                printf("Please enter value for row and column in the range of 0 - %d\n", N - 1);
            }
        }

        if (checkValid(r, c)) {
            A[r][c] = PLAYER;
            display();
            if (checkWinner()) {
                return 0;
            }
        } else {
            printf ("Wrong move, reneter data\n");
            continue;
        }

        player = (player + 1) % 2;
        if (isFull()) {
            printf ("Game draw\n");
            break;
        }
   }
   return 0;
}
