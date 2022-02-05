// Max Increasing Subsequence
#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;
#define MAX 100

int 
solve (int n, int *coins, int numCoin) {
	int waysSize = n +1;
	int ways[waysSize];
	// init ways
	for (int i = 0; i < waysSize; i++) {
	  ways[i] = 0;
	}

	ways[0] = 1;
	for (int i = 0; i < numCoin; i++) {
	  for (int j = 0; j < waysSize; j++) {
			if (coins[i] <= j) {
				ways[j] += ways[(j - coins[i])];
			}
		}
	} 
	return ways[n];
}

int
main() {
  int n = 5;
  int cs = 3;
  int c[cs] = {1, 2, 3};

  cout << "n = " << n << " #soln = " << solve(n, c, cs) << endl;
  return 0;
}
