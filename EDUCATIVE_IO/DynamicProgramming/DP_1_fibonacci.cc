#include <stdio.h>
#include <iostream>

int lookup[18] = {-1};

// memoization
int
fib_mem(int n) {
  if (lookup[n] == -1) {
    if (n == 0) 
      lookup[n] = 0;
    else if (n == 1)
      lookup[n] = 1;
    else
      lookup[n] = fib_mem(n-1) + fib_mem(n-2);
  }
  return lookup[n];
}

//  tabulation (top down)
int
fib_tab(int n) {
  int f[n+1];
  int i;
  f[0] = 0; 
  f[1] = 1;
  for(i = 2; i <= n; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return f[n];
}

int
fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n-1) + fib(n-2));
}

void fibo(int n) {
  int i = 0;
  for (int j = 0; j < n; j++) lookup[j] = -1;
  while (i < n) {
    printf( "%3d ", fib_tab(i));
    i++;
  }
	printf("\n");
}

void
fibonacci(int n) {
	if (n < 1) return; // error

	int f0 = 0;
	int f1 = 1;

  // print first n fibonacci numbers
	while (n) {
		printf("%3d ", f0);
		int tmp = f0;
		f0 = f1;
		f1 = tmp + f1;
		n--;
	}

	printf("\n");
	return;
}

int
main () {
  fibonacci(10);
  fibo(10);
  return 0;
}
