// In every iteration pick the maximum of these two values:
//   Max Sum of the last iteration.
//   Max Sum of second last iteration + current iteration index.
#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int 
find_max_sum_nonadjacent(int *A, int n) {
  int result[n] = {0};
  int k = 0;
  int s = 0;
  int i = 0;
  int maxSum = 0;
  result[k++] = A[0];
	for (int i = 1; i < n; i++) {
    result[k] = max(result[k-1], A[i]);
    if (k-2 >= 0)
    result[k] = max(result[k], A[i] + result[k-2]);
    k++;
  }

   return result[k-1];
}

int
main () {
  int v[] = {1, -1, 6, -4, 2, 2};

 // int v[] = {1, 2, 6, -4, 2, 2};
  int sum = find_max_sum_nonadjacent(v, sizeof(v) / sizeof(v[0]));
  cout << "Max sum of nonadjacent subsequence: " << sum << endl;
	return 0;
}
