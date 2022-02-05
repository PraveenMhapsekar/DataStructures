// longest commom subsequence
#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int 
find_logest_increasing_subseq(int *A, int n) {

  int lis[n];  // init all elemnts to 1, as even single subsequence is increasing subseq

	for (int i = 0; i < n; i++) {
     lis[i] = 1;
  }
  int maxLis = 0;
  lis[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i ; j++) {
			if ((A[j] < A[i])) { 
				lis[i] = max(lis[i], lis[j] + 1);
      } 
    }
  }

	for (int i = 0; i < n; i++) {
    printf("%3d ", lis[i]);
		maxLis = max(maxLis, lis[i]);
  }
  printf("\n");
  return maxLis;
}

int
main () {
  int v[] = {10, 9, 8, 7, 6, 5, 4, 4, 4};
 // int v[] = {10, 22, 9, 33, 21, 50, 41, 60};
  int n = sizeof(v) / sizeof(v[0]);
	for (int i = 0; i < n; i++) {
    printf("%3d ", v[i]);
  }
  printf("\n");
  int sum = find_logest_increasing_subseq(v, n);
  cout << "Max incr subsequence: " << sum << endl;
	return 0;
}
