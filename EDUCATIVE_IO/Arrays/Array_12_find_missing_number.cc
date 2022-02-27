/*
	We are given an array containing n distinct numbers taken from the range 0 to n.
  Since the array has only n numbers out of the total n+1 numbers, find the missing number.
*/
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    int i = 0;
    // Cyclic sort
    while (i < nums.size()) {
      if (nums[i] < nums.size() && nums[i] != nums[nums[i]]) {
        swap(nums, i, nums[i]);
      } else {
        i++;
      }
    }

    // find the first number missing from its index, that will be our required number
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i) {
        return i;
      }
    }

    return nums.size();
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

void
missingNum(vector<int> v) {
  int size = v.size();
  int actual_sum = 0;
  int expected_sum = (size * (size + 1)) / 2; 
  for (int i = 0; i < size; i++) {
    actual_sum += v[i];
  }
  cout << "missing number " << (expected_sum - actual_sum) << endl;
}

int 
main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  missingNum(v1);

  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  missingNum(v1);
}
