/*
	Given an array of positive numbers and a positive number ‘K’
	find the maximum sum of any contiguous subarray of size ‘K’.

	Time Complexity
		The time complexity of the above algorithm will be O(N)

	Space Complexity
		The algorithm runs in constant space O(1)
*/

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class MaxSumSubArrayOfSizeK {
 public:
  static int 
  findMaxSumSubArray(int k, const vector<int>&arr) {
    int maxSum = 0, windowSum;
    for (int i = 0; i <= arr.size() - k; i++) {
      windowSum = 0;
      for (int j = i; j < i + k; j++) {
        windowSum += arr[j];
      }
      maxSum = max(maxSum, windowSum);
    }

    return maxSum;
  }
 
  // better approach 
  static int 
  findMaxSumSubArray1(int k, const vector<int> &arr) {
    int windowSum = 0, maxSum = INT_MIN;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      windowSum += arr[windowEnd];  // add the next element
      // slide the window, we don't need to slide if we've not hit the required window size of 'k'
      if (windowEnd >= k - 1) {
        maxSum = max(maxSum, windowSum);
        windowSum -= arr[windowStart];  // subtract the element going out
        windowStart++;                  // slide the window ahead
      }
    }

    return maxSum;
  }
};

int 
main(int argc, char* argv[]) {
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray1(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray1(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}
