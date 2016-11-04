#include <stdio.h>
#include <stdlib.h>

#define N 8

//int AA[N] = {7, 6,5,3,3,2,1,0};
int A[N];
int testArray[N] = {0,1,2,3,3,5,6,7};
<<<<<<< HEAD
int AA[N] = {17, 36, 225, 23,123,2,1,0};

char
*menu [] = {
            "",
            "Bubble Sort", 
            "Selection Sort",
            "Insertion Sort",
            "Shell Sort",
            "Counting Sort",
            "Bucket sort",
            "Radix Sort",
            "Quick Sort",
            "Merge Sort",
            "Heap Sort"
            ""    
            };

typedef enum 
sortMenu {
            sortlistStart,
            bubblesort,
            selectionsort,
            insertionsort,
            shellsort,
            countingsort,
            bucketsort,
            radixsort,
            quicksort,
            mergesort,
            heapsort,
            sortListEnd,
          } sortMenu_t;
=======

int AA[N] = {17, 36, 225, 23,123,2,1,0};

char *menu [] = {
                "",
                "Bubble Sort", 
                "Selection Sort",
                "Insertion Sort",
                "Shell Sort",
                "Counting Sort",
                "Bucket sort",
                "Radix Sort",
                "Quick Sort",
                "Merge Sort",
                "Heap Sort"
                ""    
                };

typedef enum sortMenu {
                sortlistStart,
                bubblesort,
                selectionsort,
                insertionsort,
                shellsort,
                countingsort,
                bucketsort,
                radixsort,
                quicksort,
                mergesort,
                heapsort,
                sortListEnd,
} sortMenu_t;
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c

void
copyArry()
{
    int i;
    for (i = 0; i < N; i++) {
        A[i] = AA[i];
    }
}

int
testSortArray() 
{
    int i;
    for (i = 0; i < N; i++) {
        if (A[i] != testArray[i]) {
            return 0;
        }
    }
    return 1;
}

void
printArray()
{
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
<<<<<<< HEAD
=======

>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
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

<<<<<<< HEAD
/* 1. Bubble Sort ************************************************************************************************************/
void
bubbleSort() 
{
    int i, j; // Pass
    for (i = 0; i < N - 1;  i++) {
=======
void
bubbleSort() 
{
    int i; // Pass
    int j;
    for (i = 0; i < N-1;  i++) {
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
        for (j = 0; j < (N - i - 1); j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
            }
        }
        printArray();
    }
}

<<<<<<< HEAD
/* 2. Selection Sort **********************************************************************************************************/
void
selectionSort() 
{
    int i, j;
    int key = 0;
    for (i = 0; i < N - 1; i++) {
        key = i; 
        for (j = i; j < N; j++) {
            if (A[j] < A[key]) {
                key = j;
            }
        }
        swap(&A[i], &A[key]);
        printArray();
=======
void
selectionSort() 
{
    int i;
    int j;
    int key = 0;
    for (i = 0; i < N-1; i++) {
       key = i; 
       for (j=i; j<N; j++) {
           if (A[j] < A[i]) {
               key = j;
           }
       }
       swap(&A[i], &A[key]);
       printArray();
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    }
}

#if 0
    int i;
    int j;
    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            if (A[j] < A[i]) {
                swap(&A[j], &A[i]);
            }
       }
       printArray();
    }
}
#endif

<<<<<<< HEAD
/* 3. Insertion Sort **********************************************************************************************************/
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
void
insertionSort()
{
    int i, j, temp;
    for (i = 1; i < N; i++) {
<<<<<<< HEAD
         for (j = i - 1; j >= 0; j--) {
=======
         temp = A[i];
         for (j = i-1; j >= 0; j--) {
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
            if (A[j] > A[j+1]) {
                swap (&A[j], &A[j+1]);
            }
        }
<<<<<<< HEAD
=======
        A[j] = temp; 
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
        printArray();
    }
}
#if 0
void
insertionSort()
{
    int i;
    int j;
    int key = 0;
    for (i = 0; i < N-1; i++) {
       key = i; 
       for (j=i; j<N; j++) {
           if (A[j] < A[i]) {
               key = j;
           }
       }
       swap(&A[i], &A[key]);
       printArray();
    }
}
#endif
<<<<<<< HEAD

/* 4. Quick Sort ************************************************************************************************************/
int
partition (int left, int right)
=======
#define BUCKET 10 // Asuming that all the elements are in the range (0 - (BUCKET - 1))
void
bucketSort()
{
    int i = BUCKET;
    int k = 0;
    int BA[BUCKET];

    for (i = 0; i < BUCKET; i++) {
        BA[i] = 0;
    }

    for (i = 0; i < N; i++) {
        BA[A[i]]++;
    }
        
    for (i = 0; i < BUCKET; i++) {
        while (BA[i]) {
            A[k++] = i;
            BA[i]--;
        }
    }
}

int partition (int left, int right)
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
{
    int pivot = A[left];
    int L = left;
    int R = right;

    while (L < R)
    {
        while ((pivot >= A[L]) && (L < right))
            L++; // All the elements to the left of L are equal to or smaller than pivot.
        while (A[R] > pivot)
            R--; // All the elements to the right of R are greater than pivot, R is now pointing at element smaller than pivot, which is suppse to be left of pivot as per above comment
        if (L < R)
            swap(&A[L], &A[R]); // swap R and L and iterate again.
    }

<<<<<<< HEAD
    swap (&A[R], &A[left]); //Swap Pivot with smallest element 
=======
    swap (&A[R], &A[left]); //SWap Pivot with smallest element 
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    printArray();
    return R; // Return new Pivot;
}

int
quickSort (int left, int right)
{
    int pivot;

    if (left < right) {
        pivot = partition(left, right);
        quickSort(left, pivot - 1);
        quickSort(pivot + 1, right); 
    }
}

<<<<<<< HEAD
/* 5. Merge Sort ************************************************************************************************************/
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
void
merge(int l, int m, int r) 
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

<<<<<<< HEAD
=======

>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    for(i = 0; i < n1; i++) {
        L[i] = A[l+i];
    }

    for(j = 0; j < n2; j++) {
        R[j] = A[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;    
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
      
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void 
mergeSort(int start, int end) 
{
   int mid;

   if (start >= end) {
       return;
   }

   mid = (start + (end - 1))/2;

   mergeSort(start, mid);
   mergeSort(mid + 1, end);
   merge(start, mid, end);

   return;
}

<<<<<<< HEAD
/* 6. Heap Sort ************************************************************************************************************/
=======
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
/*
 * n -> heap size
 * i -> index
 */
<<<<<<< HEAD
void 
heapify (int n, int i) 
=======
void heapify (int n, int i) 
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
{
   int largest = i;    /* Root        */
   int lc = i * 2 + 1; /* Left child  */
   int rc = i * 2 + 2; /* Right child */
  
   if ((A[largest] < A[lc]) && (lc < n)) {
        largest = lc;
   }

   if ((A[largest] < A[rc]) && (rc < n)) {
        largest = rc;
   }

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
    for (i = N - 1; i >= 0; i--) {
        swap (&A[i], &A[0]); /* Extract heighest element and swap/store at the end of the array */
        heapify(i, 0);       /* Heapify new root */
    } /* Reduce array size (i--) */
}

<<<<<<< HEAD
/* 7. Bucket Sort ***********************************************************************************************************/
#define BUCKET 10 // Asuming that all the elements are in the range (0 - (BUCKET - 1))
void
bucketSort()
{
    int i;
    int k = 0;
    int BA[BUCKET];

    for (i = 0; i < BUCKET; i++) 
        BA[i] = 0;

    for (i = 0; i < N; i++) 
        BA[A[i]]++;
        
    for (i = 0; i < BUCKET; i++) {
        while (BA[i]) {
            A[k++] = i;
            BA[i]--;
        }
    }
}

/* 8. Counting Sort ************************************************************************************************************/
#define COUNT 1000
void
countingSort() 
{
    int i;
    int k = 0;
    int count[COUNT];

    for (i=0; i < COUNT; i++) {
=======
void
countingSort(int exp) 
{
    int k = 1000;
    int count[k];
    int p = 0;
    int i = 0;

    for (i=0; i < k; i++) {
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
        count[i] = 0;
    }

    for (i=0; i < N; i++) {
        count[A[i]]++;
    }

    for (i=0; i < k; i++) {
<<<<<<< HEAD
        while (count[i]) {
            A[k++] = i;
            count[i]--;
=======
        while (count[i] > 0) {
            A[p++] = i;
            count[i] = count[i] - 1;
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
        }
    }
}

<<<<<<< HEAD
/* 9. Radix Sort ************************************************************************************************************/
void
radixSort()
{
    int max, i, k;
    int m = 0;
    int digits = 0;
=======
void
radixSort()
{
    int max;
    int m = 0;
    int digits = 0;
    int i;
    int k;
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c

    for (i = 0; i < N; i++) {
        if (A[i] > A[m]) {
            m = i;
        }
    }

    max = A[m];

    if (max > 0) {
        digits++;
        while (max / 10) {
            digits++;
            max = max / 10;
        }
    }

    k = 10;
    for (i = 0; i < digits; i++) {
       countingSort(k);
       k = k * 10;
    }
}

/***************************************************************************************************************************/
void
printMenu ()
{
    sortMenu_t i;
    printf("\n\nMenu:\n");
    for (i = sortlistStart + 1; i < sortListEnd; i++) {
          printf("%2d. %-15s", i, menu[i]);
          if (((i % 5) == 0) || (i == sortListEnd - 1)) { /* Print 5 menu items per line */
              printf ("\n");
          }
    }
    printf ("Enter your choice :\n");
}

int
getChoice(sortMenu_t *cc) 
{
<<<<<<< HEAD
    int n, c;

=======
    int n;
    int c;
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
    if (((n = scanf("%d", &c)) != 1) || (c > sortListEnd) || (c < bubblesort)) {
        printf ("\nWrong input!!!\nPlease get familiar with menu options to run this program\nGood Bye for now!!!\n");
        return 0;        
    }

    *cc = c;
    return 1;
}

int
main (void)
{
    sortMenu_t c;

    printMenu();

    while (1) {
        if (getChoice(&c) == 0) {
            return 0; 
        }        

        copyArry();  // Read unsorted array into to be sorted array A[]
        printf("Your want to use %s\nArray to be sorted is...\n", menu[c]);
        printArray();
        printf("%s...\n", menu[c]);

        switch (c) {
            case bubblesort:
                bubbleSort();
                break;
            case selectionsort:
                selectionSort();
                break;
            case insertionsort:
                insertionSort();
                break;
            case mergesort:    
                mergeSort(0, (N-1));
                printArray();
                break;
            case bucketsort:
                bucketSort();
                printArray();
                break;
            case quicksort:
                quickSort(0, N-1);
                printArray();
                break;
            case heapsort:
                heapSort();
                printArray();
                break;
            case countingsort:
                countingSort(1);
                printArray();
                break;
            case radixsort:
                radixSort();
                printArray();
                break;
            default:
                printf ("\bYour choice %s not yet implemeneted\n", menu[c]);   
                printMenu();
                continue;
        }
<<<<<<< HEAD
#ifdef TEST_YOUR_WORK
=======
#ifdef TESTYOURWORK
>>>>>>> 7afd4cae90cfc1e317f6f260a9f4a587bad3ec3c
        // Test sorted array aginst expected results
        if (!testSortArray()) {
             printf("\n\n\b\b Error sorting failed\n");
        }
#endif
        // Print menu for next execution option
        printMenu(); 
    }

    return 0;
}
