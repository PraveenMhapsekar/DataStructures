#include <iostream>
#include <string.h>
#include <string>
using namespace std; 

void
shuffle( 

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
