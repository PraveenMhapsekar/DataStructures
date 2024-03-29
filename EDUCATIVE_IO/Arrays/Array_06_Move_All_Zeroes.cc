/*
 Given an integer array,
 move all elements that are 0 to the left while maintaining the order of other elements in the array. 
 The array has to be modified in-place.
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <vector>

using namespace std;
// basically push call non zero elements to the rightmost
void
pushZeros2End(vector<int> &A) {
  int size = A.size();

  if (size < 2) return;

  int write = size - 1;
  int read  = size - 1;

  while (read >= 0) {
    if (A[read] != 0) {
			A[write] = A[read];
			write--;
			read--;
    } else {
			// element is zero dont update write pointer
			read--;
    }
  }

  while (write >= 0) {
		A[write] = 0;
		write--; 
  }

  return; 
}

int
main () {
	vector<int> v = {1, 10, 20, 0, 59, 63, 0, 88, 0};

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
  cout << endl;

	pushZeros2End(v);

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}

	printf("\n");
  return 0;
}
