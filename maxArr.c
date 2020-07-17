#include <stdio.h>
#include <stdlib.h>
/*
	You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
	f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

	For example,

	A=[1, 3, -1]

	f(1, 1) = f(2, 2) = f(3, 3) = 0
	f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
	f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
	f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

	So, we return 5.
*/

int
max(int x, int y) {
  return ((x > y) ? x : y); 
}

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int 
maxArr(int* A, int n1) {
	int sum = 0;
	int maxSum = 0;
	int i;
	int j;

	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {
			sum = abs(A[i] - A[j]) + abs(i - j);
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	return maxSum;
}

// main function
int 
main() {
  int arr[] = {1, 3, -1 };
	int n = sizeof(arr)/sizeof(arr[0]);

	printf(" %d \n", maxArr(arr, n));

	return 0;
}
