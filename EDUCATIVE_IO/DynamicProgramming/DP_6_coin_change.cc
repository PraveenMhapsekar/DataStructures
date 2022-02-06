// Max Increasing Subsequence
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <iomanip> 

using namespace std;

int 
solve (int n, int *coins, int numCoin) {
	int waysSize = n + 1;
	int ways[waysSize];
	// init ways

  cout << "ways[xx] ";
	for (int i = 0; i < waysSize; i++) {
    cout << setw(2) << i << " ";
	  ways[i] = 0;
	}
  cout << endl;

	ways[0] = 1;
	for (int i = 0; i < numCoin; i++) {
    cout << "coin["<< setw(2) << coins[i] << "] ";
	  for (int j = 0; j < waysSize; j++) {
			if (coins[i] <= j) {
				ways[j] += ways[(j - coins[i])];
			}
		  cout << setw(2) << ways[j] << " ";
		}
    cout << endl;
	} 

  cout << endl;
	return ways[n];
}

int
main() {
  int n = 5; // sum
  int cs = 3; //coin array size
  int c[cs] = {1, 2, 3};
  int sol = solve(n, c, cs);
  cout << "n = " << n << " #soln = " << sol << endl;
  return 0;
}
