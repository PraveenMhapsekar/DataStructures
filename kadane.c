#include <stdio.h>

int max(int x, int y) {
  return ((x > y) ? x : y); 
}

void
kadane(int *A, int n) {
  int tmpMax = 0;
  int maxSum = A[0];
  int i;
  int eIdx =  0;
  int idx = -1;
  int sIdx;

  for (i = 0; i < n; i++) {
    //   tmpMax = max(A[i], A[i] + tmpMax);
    if (A[i] > (A[i] + tmpMax)) {
      // if current element is greater than current val plus tmpmax
      // - use current val
      // - start of new subArray
			idx = i;
      tmpMax = A[i];
    } else {
      tmpMax = A[i] + tmpMax;
    }

    if (tmpMax > maxSum) {
      // new maxSum
      maxSum = tmpMax;
      // update idx'es
      eIdx = i;
      sIdx = idx;
    }
  }

  // Print results
  printf ("maxSum = %d\n sIndx = %d endIdx = %d\n", maxSum, sIdx, eIdx);
  for (i = sIdx; i <= eIdx; i++) {
    printf(" %d ", A[i]);
  }
  printf("\n");

  return;
}

// main function
int 
main() {
  //int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  int arr[] = {  0, -461, -125, -404, -59, -322, -495, -288, -341, -449, -313, -192, -214, -389, -202, -183, -72, -416, -455, -187, -242, -416, 39, -198, -338, -465, -248, -25, -398, -97, -461, -214, -423, -407, -77, -190, -67, -178, -410, -160, 72, -350, -31, -85, -247, -319, -462, -303, -48, -354, -110, 17, 60, 19, 80, -218, -28, -426, -366, -140, 50 };
  //	int arr[] = { -2, -1, -3, -4, -1, -2, -1, -5, -4 };
	int n = sizeof(arr)/sizeof(arr[0]);

	kadane(arr, n);

	return 0;
}
