#include <stdio.h>

#define SIZE 8
int A[SIZE];
int N = SIZE;
int curSize;

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

/*
 * n -> heap size
 * i -> index
 */
void heapify (int n, int i) 
{
   int largest = i;    /* Root        */
   int lc = i * 2 + 1; /* Left child  */
   int rc = i * 2 + 2; /* Right child */
  
   if ((A[largest] < A[lc]) && (lc < n))
        largest = lc;
   

   if ((A[largest] < A[rc]) && (rc < n)) 
        largest = rc;
   

   if (i != largest) {
       swap (&A[i], &A[largest]); /* New root          */
       heapify(n, largest);       /* Heapify new child */
   }
}

void
heapSort()
{
    int i;
  
    /* Build heap from initial array */ 
    for (i = (N/2) - 1; i >= 0; i--) {
        heapify(N, i);
    }
    /* Extract elements from the heap in sorted manner */
    for (i = curSize - 1; i >= 0; i--) {
        swap (&A[i], &A[0]); /* Extract heighest element and swap/store at the end of the array */
        heapify(i, 0);       /* Heapify new root */
    } /* Reduce array size (i--) */
}

int 
pop()
{
   int ret;
   ret = A[0];
   swap(&A[curSize-1], &A[0]);
   curSize--;
   heapify(curSize, 0);
   return (ret);
}

void
insert(int data) 
{
    int i;
    if (curSize >= SIZE)
        return;

    A[curSize] = data;
//    swap(&A[curSize], &A[0]);

  //  for (i = curSize - 1; i >= 0;  i--) {
    if (curSize > 0)
        heapify(curSize , (curSize/2) - 1); 
    //}

    curSize++;
}

void
printArray(size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }

    printf("\n"); 
}

int
main(void)
{
    int i;
    insert(10);
    printArray(curSize);
    insert(1);
    printArray(curSize);
    insert(110);
    printArray(curSize);
    insert(16);
    printArray(curSize);
    insert(21);
    printArray(curSize);
    insert(33);
    printArray(curSize);
    insert(24);
    insert(11);
    insert(12);
    
    printArray(curSize);
    for (i = 0; i < curSize; i++) {
//        printf("%d \n", pop());
    }
    heapSort();
    printArray(curSize);
    return 0;
}
