#include <stdio.h>
#include <iostream>

int
fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n-1) + fib(n-2));
}

void fibo(int n) {
  int i = 0;
  while (i < n) {
    printf("%3d ", fib(i));
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
