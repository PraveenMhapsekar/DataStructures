// Max Increasing Subsequence
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <iomanip> 

using namespace std;

int 
solve (int *coins, int N, int T) {
  T =  T + 1; // number of solutions excluding 0th i and j row
	int dp[N][T];
	// init dp

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < T; j++) {
			dp[i][j] = 0;
    }
	}
  // init 0th row
	for (int i = 0; i < N; i++) {
		dp[i][0] = 0;
  }

  // First row, for each target sum, there is only one solution
	for (int j = 0; j <= T; j++) {
		dp[0][j] = 1;
  }

  cout << endl;

	for (int i = 0; i < N; i++) {
    cout << "coin["<< setw(2) << coins[i] << "] ";
	  for (int j = 1; j < T; j++) {
      if (i > 0) {
				dp[i][j] = dp[i-1][j];
      }
			if ((i > 0) && (coins[i] <= j)) {
				// above cell plus jth multiple from current row, Think!!! 
				dp[i][j] = dp[i][j] + dp[i][(j - coins[i])];
			}
			cout << setw(2) << dp[i][j] << " ";
    }
    cout << endl;
	} 

	return dp[N-1][T-1];
}

int
main() {
  int n = 5; // sum
  int cs = 3; //coin array size
  int c[cs] = {1, 2, 3};
  int sol = solve(c, cs, n);
  cout << "n = " << n << " #soln = " << sol << endl;

  return 0;
}
