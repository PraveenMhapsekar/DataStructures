using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LCS {

public:
  int findLCSLength(const string &s1, const string &s2) {
  //   vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
    int dp[s1.length() + 1][s2.length() + 1];
    for (int i = 0; i <= s1.length(); i++) {
      for (int j = 0; j <= s2.length(); j++) {
        dp[i][j] = 0;
      }
    }
    int maxLength = 0;
    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          maxLength = max(maxLength, dp[i][j]);
        }
      }
    }
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  LCS *lcs = new LCS();
  cout << lcs->findLCSLength("abdca", "cbda") << endl;
  cout << lcs->findLCSLength("passport", "ppsspt") << endl;

  delete lcs;
}
