#include <stdio.h>
#include <stdlib.h>

#define N 8

int A[N] = {0,1,2,3,3,5,6,7};


void
printArray()
{
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n"); 
}

void 
swap (int *a, int *b)
{
    if (a == b) {
        return;
    }

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void
insertionSort()
{
    int i, j;
    int tmp;

    for (i = 1; i < N; i++) {
        tmp = A[0];
        for (j = i - 1; j >= 0; j--) {
            if (A[j] < A[j+1])
                swap(&A[j], &A[j+1]);
            printArray();
        }
//        A[j] = tmp;
    }
}

int 
main(void)
{
    printArray();
    insertionSort();
    printArray();
    return 0;
}
