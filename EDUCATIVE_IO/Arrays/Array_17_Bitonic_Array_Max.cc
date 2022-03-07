/*
	Find the maximum value in a given Bitonic array. 
	An array is considered bitonic if it is monotonically increasing and then monotonically decreasing.
	Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].
*/
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class MaxInBitonicArray {
 public:
  static int 
  findMax(const vector<int> &arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] > arr[mid + 1]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    // at the end of the while loop, 'start == end'
    return arr[start];
  }
};

int 
main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}

