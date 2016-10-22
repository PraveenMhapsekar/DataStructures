#include <stdio.h>
#define ARRSIZE 11

int arr[ARRSIZE] = {10, 9, 4, 5, 2, 1, 7, 8, 0, 3, 6};

void bubbleSort() {
    printf("%s\n", __func__);
    int i, j;
    int temp;

    for(i = 0; i < ARRSIZE; i++) {
        for(j = 0; j < (ARRSIZE - i - 1); j++) {
          if( arr[j] > arr[j+1]) {
           temp = arr[j];
           arr[j] = arr[j+1];
           arr[j+1] = temp;
          }
        }
    }
}

static int counter;

static int counter1;

int search(int key) {

    int i;
    for (i = 0; i < ARRSIZE; i++) {
        counter1++;
        if (arr[i] == key)
            return 1;
    }
    
    return 0;
}

int 
binarySearch (int start, int end, int key) {
    int mid;
    int rv = 0;
    counter++;

    if (start > end)
        return rv;

    mid = (start + end ) / 2;

    if (arr[mid] == key)
        return 1;

    if (key > arr[mid])
        rv =  binarySearch(mid + 1, end, key);
    else
        rv =  binarySearch(start, mid - 1, key);

    return rv;
}

void printArry() {
    int i;
    for(i = 0; i < ARRSIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {

    printArry();    
    bubbleSort();
    printArry();    
    if (binarySearch(0, ARRSIZE - 1, 100))
       printf("Success\n");
    else
       printf("Fail\n");
//    printArry();    
    printf("counter %d\n\n", counter);

    if (search(100))
       printf("Success\n");
    else
       printf("Fail\n");
    printf("counter %d\n\n", counter1);
    return 0;
}


