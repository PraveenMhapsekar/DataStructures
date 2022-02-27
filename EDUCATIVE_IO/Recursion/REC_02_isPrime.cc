#include <stdio.h>
#include <iostream>

using namespace std;

// Iterative
bool
primeHelper1(int x) {
  if (x <= 1) return false;

  for (int i = x/2; i > 1; i = i / 2) {
    if ((x % i) == 0)
      return false;
  }

  return true;
} 

// recursive
bool
primeHelper(int x, int i) {
	if (x <= 1) return false;

	if (i == 1) return true;
  
  if ((x % i) == 0) {
    return false;   
  } else {
		return  primeHelper(x, i/2);
  }
}

bool
prime(int x) {
  return primeHelper(x, x/2);
  // return primeHelper1(x);
}

int
main () {
  int x = 17;
  x = 0;
  cout << "IS " << x << " prime? " <<  (prime(x) ? "true" : "false") << endl; 
  x = 1;
  cout << "IS " << x << " prime? " <<  (prime(x) ? "true" : "false") << endl; 
  x = 2;
  cout << "IS " << x << " prime? " <<  (prime(x) ? "true" : "false") << endl; 
  x = 15;
  cout << "IS " << x << " prime? " <<  (prime(x) ? "true" : "false") << endl; 
  x = 17;
  cout << "IS " << x << " prime? " <<  (prime(x) ? "true" : "false") << endl; 
  return 0;
}
