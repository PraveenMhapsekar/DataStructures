#include <stdio.h>

#define N 27
#define M (n/2) // Mid Point

int
main (void)
{
  int i;
  int j;
	int n = N % 2 ? N : (N +1);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if ((j == (M + i)) || 
					 (j == (M - i)) || 
					 (j == (i - M)) ||
					 (j == (3*M - i))) { // 2M - (i - M) --> 3M -i
				printf ("*");
			} else {
				printf(" ");
			}
		}
		printf ("\n");
	}

	return 0;
}
