#include <stdio.h>

#define SIZE 8

int A[SIZE] = {4, 5, 7, 8, 1, 3, 2, 6};
int N = SIZE;

void swap(int *A, int *B)
{
   if (A == B)
       return;

   *A = *A ^ *B;
   *B = *A ^ *B;
   *A = *A ^ *B;
}

void
print()
{
    int i;
    for(i = 0; i < N; i++)
        printf("%2d ", A[i]);
    printf("\n");
}

void
heapify(int n, int s)
{
    int largest = s;
    int lc = s * 2 + 1;
    int rc = s * 2 + 2;
    
    if ((lc < n) && (A[largest] < A[lc]))
        largest = lc;

    if ((rc < n) && (A[largest] < A[rc]))
        largest = rc;

    if (largest != s) {
       swap(&A[largest], &A[s]);
       heapify(n, largest);
    }
}

void
heapSort() {

    int i;
    for(i = (N/2) - 1; i >=0; i--)
        heapify(N, i);

    for (i= N - 1; i >= 0; i--) {
        swap(&A[i], &A[0]);
        heapify(i, 0);
    }
}

int
main(void)
{
    print();
    heapSort();
    print();
    return 0;
}
