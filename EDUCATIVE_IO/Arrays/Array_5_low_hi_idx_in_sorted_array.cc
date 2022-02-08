/*
	Given a sorted array of integers, return the low and high index of the given key. 
  You must return -1 if the indexes are not found.
*/
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int
find_low_index(vector<int>& arr, int key) {
  int low = 0;
  int high = arr.size() - 1;
  int mid = high / 2;

  while (low <= high) {
    int mid_elem = arr[mid];

    if (mid_elem < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    mid = low + (high - low) / 2;
  }

  if (low < arr.size() && arr[low] == key) {
    return low;
  }

  return -1;
}

int
find_high_index(vector<int>& arr, int key) {
  int low = 0;
  int high = arr.size() - 1;
  int mid = high / 2;

  while (low <= high) {
    int mid_elem = arr[mid];

    if (mid_elem <= key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    mid = low + (high - low) / 2;
  }
  
  if (high == -1)
    return high;
  
  if (high < arr.size() && arr[high] == key) {
    return high;
  }

  return -1;
}

int main(int argc, char* argv[]) {
    vector<int> arr = {1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6};
    int key = 5;
    int low = find_low_index(arr, key);
    int high = find_high_index(arr, key);
    cout << "Low Index of " << key << ": " << low <<endl;
    cout << "High Index of " << key << ": "<< high <<endl;
    
    key = -2;
    low = find_low_index(arr, key);
    high = find_high_index(arr, key);
    cout << "Low Index of " << key << ": "<< low <<endl;
    cout << "High Index of " << key << ": "<< high <<endl;
}  
