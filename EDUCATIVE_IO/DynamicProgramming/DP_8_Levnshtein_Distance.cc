// Max Increasing Subsequence
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <iomanip> 
#include <string.h>

using namespace std;

int
mini (int x, int y, int z) {
  int ret = x;
  if (x < y) {
    if (x < z) {
      ret = x;
    }
  } else if (y < z) {
    ret = y;
  } else {
		ret = z;
  }
  return ret;
}

int
levenshtein_distance(char *s1, char *s2) {
  int n = strlen(s1) + 1;
  int m = strlen(s2) + 1;

  if (n == 0) return m;
  if (m == 0) return n;

  int cost;
  int dp[n][m];

  // init dp arry
  for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
      dp[i][j] = 0;
    }
  }

  // init 0th col, base case when S2 is empty
  for (int i = 0; i < n; i++) {
  //  cout << s1[i] << " ";
    dp[i][0] = i;
  }

  // init print first row (base case when S1 ie empty)
  cout << endl;
  cout << "  ";
	for (int j = 0; j < m; j++) {
    cout << s2[j] << " ";
		dp[0][j] = j;
	}
  cout << endl;

  // process
  for (int i = 1; i < n; i++) {
   cout << s1[i-1] << " ";
    for (int j = 1; j < m; j++) {
      if (s1[i-1] != s2[j-1]) { 
        cost = 1; // if not matching cost is 1
      } else {
        cost = 0;
      }

      dp[i][j] = mini(dp[i-1][j] + 1,  // Deletion
                     dp[i][j-1] + 1,  // Insertion
                      dp[i-1][j-1] + cost); // Substitution
#if 0
      // pick min of left, top and let-top-diagonal cell 
      dp[i][j] = min(dp[i-1][j] + 1,  // Deletion
                      min(dp[i][j-1] + 1,  // Insertion
                      dp[i-1][j-1] + cost)); // Substitution
#endif
      cout << dp[i][j] << " " ;
    }
    cout << endl;
  }
  
  return dp[n-1][m-1];
}


int
main() {
  int ans;
  char *s1;
  char *s2;
  s1 = "kitten";
  s2 = "sitting";
  ans = levenshtein_distance(s1, s2);
  cout << endl << "min edits " << ans << endl << endl;
  s1 = "";
  s2 = "";
  ans = levenshtein_distance(s1, s2);
  cout << endl << "min edits " << ans << endl << endl;
  return 0;
}
