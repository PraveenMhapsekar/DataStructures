#include <stdio.h>
#include <iostream>

using namespace std;

// recursive
int
gcd(int x, int y) {
	int ret;
	if (x == y) return x;

	if (x > y)
		ret = gcd(x-y, y);
	else if (y > x)
	  ret = gcd(x, y-x);

	return ret;
}

// iterative
int 
gcd1(int x, int y) {
  while (x != y) {
    if (x > y) 
      x = x  - y;
    else if (y > x) 
      y = y - x;
  }
  return x;
} 

int
GCD(int x, int y) {
	int gcd;
	int smallnum =  x > y ? y : x;

	for (int i = 0; i <= smallnum; i++) {
	  if (((x % i) == 0) && ((y % i) == 0)) {
			gcd = i;
	  }
	}
	return gcd;
}

int
main () {
  int x = 36;
  int y = 54;
  cout << "gcd of " << x << " and " << y << " is " << GCD(x, y) << endl; 
  cout << "gcd of " << x << " and " << y << " is " << gcd(x, y) << endl; 
  cout << "gcd of " << x << " and " << y << " is " << gcd1(x, y) << endl; 
  return 0;
}
