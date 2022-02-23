/*
	Given a sorted array of integers, return the lo and hi index of the given key. 
  You must return -1 if the indexes are not found.
*/
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int
find_lo_index(vector<int> &arr, int key) {
  int lo = 0;
  int hi = arr.size() - 1;
  int mid = hi / 2;

  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    int mid_elem = arr[mid];

    if (mid_elem < key) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  if (lo < arr.size() && arr[lo] == key) {
    return lo;
  }

  return -1;
}

int
find_hi_index(vector<int> &arr, int key) {
  int lo = 0;
  int hi = arr.size() - 1;
  int mid = hi / 2;

  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;

    int mid_elem = arr[mid];

    if (mid_elem <= key) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  
  if (hi == -1)
    return hi;
  
  if (hi < arr.size() && arr[hi] == key) {
    return hi;
  }

  return -1;
}

int main(int argc, char* argv[]) {
    vector<int> arr = {1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6};
    int key = 5;
    int lo = find_lo_index(arr, key);
    int hi = find_hi_index(arr, key);
    cout << "Low Index of " << key << ": " << lo <<endl;
    cout << "High Index of " << key << ": "<< hi <<endl;
    
    key = -2;
    lo = find_lo_index(arr, key);
    hi = find_hi_index(arr, key);
    cout << "Low Index of " << key << ": "<< lo <<endl;
    cout << "High Index of " << key << ": "<< hi <<endl;
}  
