using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
 public:
  virtual int canPartition(const vector<int> &num) {
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
      sum += num[i];
    }

    int n = num.size();
    vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));

    // populate the sum=0 columns, as we can always form '0' sum with an empty set
    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }

    // with only one number, we can form a subset only when the sum is equal to that number
    for (int s = 0; s <= sum / 2; s++) {
      dp[0][s] = (num[0] == s ? true : false);
    }

    // process all subsets for all sums
    for (int i = 1; i < num.size(); i++) {
      for (int s = 1; s <= sum / 2; s++) {
        // if we can get the sum 's' without the number at index 'i'
        if (dp[i - 1][s]) {
          dp[i][s] = dp[i - 1][s];
        } else if (s >= num[i]) {
          // else include the number and see if we can find a subset to get the remaining sum
          dp[i][s] = dp[i - 1][s - num[i]];
        }
      }
    }

    int sum1 = 0;
    // Find the largest index in the last row which is true
    for (int j = sum / 2; j >= 0; j--) {
      if (dp[n - 1][j] == true) {
        sum1 = j;
        break;
      }
    }

    int sum2 = sum - sum1;
    return abs(sum2 - sum1);
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
