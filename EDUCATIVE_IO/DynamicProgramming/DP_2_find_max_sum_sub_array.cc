// use kadane's algorithm

#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int
find_max_sum_sub_array(int *A, int n) {
  int beg;
  int end;
  int tmpSum = INT_MIN;
  int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
     if (A[i] > A[i] + tmpSum) {
       beg = i;
       tmpSum = A[i];
     } else {
       tmpSum = tmpSum + A[i];
       end = i;
     }

     if (maxSum < tmpSum) {
       maxSum = tmpSum;
     }
   }

   for (int i = beg; i < end; i++) {
     printf("%d ", A[i]);
   }

   printf("\n");
   return maxSum;
}

int
main () {
	int v[] = {-4, 2, -5, 1, 2, 3, 6, -5, 1};
	cout << "Sum of largest subarray: " << find_max_sum_sub_array(v, sizeof(v) / sizeof(v[0])) << endl;
	return 0;
}
