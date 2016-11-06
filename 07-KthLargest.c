/*
 * Select Kth largest value in the array. Given an unsorted array of size n, and a value k. Select the kth largest value from the array. 
 *
 * For example: 
 *
 * Array is [5, 3, 9, 1], n is 4 
 * k = 0 => 9 
 * k = 1 => 5 
 * k = 3 => 1
 *
 */
#include <stdio.h>

#define MAX 4
int A[MAX] = {5, 3, 9, 1};

printArray () 
{
    int i;
    for (i = 0; i < MAX; i++) 
        printf ("%3d ", A[i]); 
    printf("\n");
}

void 
swap (int *a, int *b)
{
    if (a == b)
        return;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void sort()
{
    int i, j;
    for (i = 1; i < MAX - 1; i++)
        for (j = i; j >= 0; j--)
            if (A[j] > A[j + 1]) 
                swap(&A[j], &A[j + 1]);
}

int
kthLargestNumber(int K) 
{
    sort();      
    printArray();
    if (K < MAX)
        printf("largest(%d) number is %d\n", K, A[K]);
}

int
main()
{
    int i;
    for (i = 0; i < MAX; i++) 
        kthLargestNumber(i);
    return 0;
}

