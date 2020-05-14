#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 8

//int AA[N] = {7, 6,5,3,3,2,1,0};
int A[N];
int testArray[N] = {0,1,2,3,3,5,6,7};
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

/* 1. Bubble Sort ************************************************************************************************************/
void
bubbleSort() 
{
  int i, j; // Pass
  for (i = 0; i <= N - 1;  i++) {
    for (j = 0; j <= (N - i - 2); j++) {
      if (A[j] > A[j + 1]) {
        swap(&A[j], &A[j + 1]);
      }
    }
    printArray();
  }
}

/* 2. Selection Sort **********************************************************************************************************
 *    Scan through the unsorted data looking for the smallest remaining element, then swap it into the position immediately 
 *    following the sorted data. Repeat until finished. 
 *    If sorting a list, you don't need to swap the smallest element into position, you could instead remove the list node from 
 *    its old position and insert it at the new.
 */
void
selectionSort() {
  int i, j, min;
  for (i = 0; i < N; i++) {
    min = i; 
    /* Find index of smallest element from unsorted array */
    for (j = i; j < N; j++) {
      if (A[j] < A[min]) {
        min = j;
      }
    }
    /* Swap smallest element from unsorted array with position immediately following sorted data */
    swap(&A[i], &A[min]);
    printArray();
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

/* 3. Insertion Sort *********************************************************************************************************
 *    Take the element immediately following the sorted data, scan through the sorted data to find the place to put it. 
 *    Repeat until finished.
 */
void
insertionSort() {
  int i, j;
  for (i = 1; i < N; i++) {
    /* Scan through sorted data (i through 0) */
    for (j = i; j > 0; j--) {
      if (A[j] < A[j-1]) {
        /* If first is smaller than previous element swap it */
        swap (&A[j], &A[j-1]);
      }
    }
    printArray();
  }
}

/* 4. Quick Sort ************************************************************************************************************/
int
partition (int left, int right) {
  int pivot = A[left];
  int L = left;
  int R = right;

  while (L < R) {
    while ((pivot >= A[L]) && (L < right)) {
      L++; // All the elements to the left of L are equal to or smaller than pivot.
    }

    while (A[R] > pivot) {
      R--; // All the elements to the right of R are greater than pivot, 
           // R is now pointing at element smaller than pivot, which is suppse to be left of pivot as per above comment
    }

    if (L < R) {
      swap(&A[L], &A[R]); // swap R and L and iterate again.
    }
  }

  swap (&A[R], &A[left]); //Swap Pivot with smallest element 
  printArray();

  return R; // Return new Pivot index;
}

int
quickSort (int left, int right) {

  int pivotIdx;

  if (left < right) {
    pivotIdx = partition(left, right);
    printf("Pivot A[%d] = %d\n\n", pivotIdx, A[pivotIdx]);
    quickSort(left, pivotIdx - 1);
    quickSort(pivotIdx + 1, right); 
  }
}

/* 5. Merge Sort ************************************************************************************************************
   -  Divide the unsorted list into n sublists, each comprising 1 element (a list of 1 element is supposed sorted).
   -  Repeatedly merge sublists to produce newly sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
*/
void
merge(int l, int m, int r) {
  int i = 0;
  int j = 0;
  int k = 0;
  int lLen = m + 1 - l; // left  length
  int rLen = r - m;     // Right length
  int L[lLen], R[rLen];

  // Copy left array
  for (i = 0; i < lLen; i++) {
    L[i] = A[l+i];
  }

  // Copy right array
  for(j = 0; j < rLen; j++) {
    R[j] = A[m+1+j];
  }

  i = 0;
  j = 0;
  k = l;

  // Merge left and right
  while (i < lLen && j < rLen) {
    if (L[i] <= R[j]) {
      A[k++] = L[i++];
    } else {
      A[k++] = R[j++];
    }
  }

  // Merge remaining: left
  while (i < lLen) {
    A[k++] = L[i++];
  }
    
  // Merge remaining: right
  while (j < rLen) {
    A[k++] = R[j++];
  }
}

void 
mergeSort(int start, int end) {
  int mid;

  if (start < end) {
    mid = ((start + (end - 1)) / 2);
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
  }

  return;
}

/* 6. Heap Sort ************************************************************************************************************/
/*
 * n -> heap size
 * i -> index
 */
void 
heapify (int n, int i) {
	int largest = i;    /* Root    */
	int lc = i * 2 + 1; /* Left child  */
	int rc = i * 2 + 2; /* Right child */

	if ((A[largest] < A[lc]) && (lc < n)) {
		largest = lc;
	}

	if ((A[largest] < A[rc]) && (rc < n)) {
		largest = rc;
	}

	if (i != largest) {
		swap (&A[i], &A[largest]); /* New root      */
		heapify(n, largest);       /* Heapify new child */
	}
}

void
heapSort() {
  int i;
  
  /* Build heap from initial array */ 
  for (i = (N/2) - 1; i >= 0; i--) {
    heapify(N, i);
  }

  /* Extract elements from the heap in sorted manner */
  for (i = N - 1; i >= 0; i--) {
    swap (&A[i], &A[0]); /* Extract heighest element and swap/store at the end of the array */
    heapify(i, 0);     /* Heapify new root */
  } /* Reduce array size (i--) */
}

/* 7. Bucket Sort ***********************************************************************************************************/
#define BUCKET 256 // Asuming that all the elements are in the range (0 - (BUCKET - 1))
void
bucketSort()
{
  int i;
  int k = 0;
  int BA[BUCKET];

  // Intialize buckets
  for (i = 0; i < BUCKET; i++) 
    BA[i] = 0;

  // Fill buckets
  for (i = 0; i < N; i++) 
    BA[A[i]]++;
    
   // Retrieve elements from the buckets
  for (i = 0; i < BUCKET; i++) {
    while (BA[i]) {
      A[k++] = i;
      BA[i]--;
    }
  }
}

/* 8. Counting Sort ************************************************************************************************************/
void
countingSort(int n, int exp) {
  int i;
  int k = 0;

#define COUNT 10
#define IDX (A[i]/exp)%10
  int count[COUNT] = {0};
  int output[n];

  /* Clear count array */
  for (i = 0; i < COUNT; i++) {
    count[i] = 0;
  }

  /* Count & store the number of numbers matching 'divide by exp' */
  for (i = 0; i < n; i++) {
    count[IDX]++;
  }

  /* Get cumulative count */
  for (i = 1; i < 10; i++) {
    count[i]+= count[i - 1];
  }

  /* build array by placing numbers from the end */
  for (i = (n - 1); i >= 0; i--) {
    output[count[IDX] - 1] = A[i]; /*These two line are important to understand the logic */
    count[IDX]--;
  }

  // Copy the output array to arr[], so that arr[] now
  // contains sorted numbers according to current digit
  for (i = 0; i < n; i++) {
    A[i] = output[i];
  }
}

/* 9. Radix Sort ************************************************************************************************************/
void
radixSort()
{
  int i, exp;
  int max = INT_MIN;

  for (i = 0; i < N; i++) {
    if (A[i] > max) {
      max= A[i];
    }
  }

  for (exp = 1; (max/exp) > 0; exp = (exp * 10)) {
    countingSort(N, exp);
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
  int n, c;

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
        countingSort(N, 1);
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
#ifdef TEST_YOUR_WORK
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
