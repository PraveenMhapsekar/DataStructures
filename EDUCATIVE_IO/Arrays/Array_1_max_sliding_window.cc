// Find maximum of sliding window

#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;


int
findMaxSldingWindow(int *A, int n, int windowSize) {
	int max = INT_MIN;
	int result[n];
	int k = 0;

	for (int i = 0; i < windowSize; i++) {
		if (A[i] > result[k]) {
			result[k] = A[i];
		}
	}

	for (int i = windowSize; i < n; i++) {
		int diff = result[k] - A[i];
		result[k+1] = result[k] + diff;
		k++;
	}

	for (int i = 0; i < k; i++)
	  cout << result[i] << " " << endl;

	cout << endl << endl;
	return -1;
}

int
findMaxSldingWindow1(int *A, int n, int windowSize) {
   int sum = 0;
   int maxSum = INT_MIN;
   int k = 0;
   for (int i = 0; i < n; i++) {
      sum += A[i];
      if (k == windowSize - 1) {
        if (sum > maxSum) {
          maxSum = sum;
        }
        if (i < (n - windowSize - 1)) {
					cout << abs(A[i - (windowSize - 1)]) << " " << endl;
					sum = sum - abs(A[i - (windowSize - 1)]);
        }
      } else {
				k++;
      }
   }

   return maxSum;
}


int 
main() {
 int num = 5;
 int A[num] = {-4 , 2, -5, 3, 6};
  int ans = findMaxSldingWindow(A, num, 3);
  cout << ans << endl;
}
