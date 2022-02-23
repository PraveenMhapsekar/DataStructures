/*
	Given a set of numbers that might contain duplicates, find all of its distinct subsets.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
public:
  static vector<vector<int>>
  findSubsets(vector<int> &nums) {
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates

    subsets.push_back(vector<int>());

    int startIndex = 0, endIndex = 0;

    for (int i = 0; i < nums.size(); i++) {
      startIndex = 0;
      // if current and the previous elements are same, create new subsets only from the subsets
      // added in the previous step
      if (i > 0 && nums[i] == nums[i - 1]) {
        startIndex = endIndex + 1;
      }

      endIndex = subsets.size() - 1;

      for (int j = startIndex; j <= endIndex; j++) {
        // create a new subset from the existing subset and add the current element to it
        vector<int> set(subsets[j]);
        set.push_back(nums[i]);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
};

int 
main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
