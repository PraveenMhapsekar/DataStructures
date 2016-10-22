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
    for (i = 0; i < MAX; i++) {
        printf ("%3d ", A[i]); 
    }
    printf("\n");
}

void 
swap (int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void sort()
{
    int i;
    int j;
    for (i = 0; i < MAX; i++) {
        for (j = i+1; j < MAX; j++) {
            if (A[i] < A[j]) {
                swap(&A[i], &A[j]);
            }
        }
    }
}

int
kthLargestNumber(int K) 
{
    sort();      
    printArray();
    if (K < MAX) {
        printf("\n %dth largest number is %d\n", K, A[K]);
    }
}

int
main()
{
    kthLargestNumber(3);
    return 0;
}

