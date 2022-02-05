#include <stdio.h>
#include <iostream>

using namespace std;

// recursive
bool
primeHelper(int x, int i) {
  bool ret;
	if (x <= 1) return false;;
	if (i == 1) return true;
  
  if ((x % i) == 0) 
     return false;   
   else 
		 ret = primeHelper(x, i/2);

   return ret;
}

bool
prime(int x) {
  return primeHelper(x, x/2);
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
