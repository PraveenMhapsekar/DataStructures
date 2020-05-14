#include <stdio.h>

int max(int x, int y) {
  return ((x > y) ? x : y); 
}

void
kadane(int *A, int n) {
  int tmpMax = A[0];
  int maxSum = A[0];
  int i;
  int eIdx;
  int sIdx = -1;

  for (i = 0; i < n; i++) {
    //   tmpMax = max(A[i], A[i] + tmpMax);
    if (A[i] > (A[i] + tmpMax)) {
      // if current element is greater than current val plus tmpmax
      // - use current val
      // - start of new subArray
      sIdx = i;
      tmpMax = A[i];
    } else {
      tmpMax = A[i] +tmpMax;
    }

    if (tmpMax > maxSum) {
      // new maxSum
      maxSum = tmpMax;
      // update end idx
      eIdx = i;
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
  int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

  //	int arr[] = { -2, -1, -3, -4, -1, -2, -1, -5, -4 };
	int n = sizeof(arr)/sizeof(arr[0]);

	kadane(arr, n);

	return 0;
}
