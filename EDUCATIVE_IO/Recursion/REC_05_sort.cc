#include <iostream>
#include <string.h>
#include <string>
using namespace std; 

void
sort(int *A, int size,  int idx) {
  if (idx == size) return;
  for (int i = 0; i < idx; i++) { 
		if (A[idx] > A[i]) {
			int tmp = A[idx];
			A[idx] = A[i];
			A[i] = tmp;
		}
  }
  sort(A, size, idx+1); 
}

int 
main() {
  int n = 4;
  int A[n] = { 4, 5, 1, 2} ;

  for (int i = 0; i < n; i++) {
    printf(" %d ", A[i]);
  }
  printf("\n");
  sort(A, n, 0);

  for (int i = 0; i < n; i++) {
    printf(" %d ", A[i]);
  }
  printf("\n");
}
