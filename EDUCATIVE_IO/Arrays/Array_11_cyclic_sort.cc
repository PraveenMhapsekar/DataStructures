/*
We are given an array containing n objects. Each object, when created, was assigned a unique number from the range 1 to n based on their creation sequence. This means that the object with sequence number 3 was created just before the object with sequence number 4.
*/
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      int j = nums[i] - 1;  // nums[i] was supposed to be at jth location, place it in correct location
      if (nums[i] != nums[j]) {
        swap(nums, i, j); // do not increment i as i got swapped and 1th lcoation could hold unsorted number
      } else {
        i++;
      }
    }
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int 
main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{1, 5, 6, 4, 3, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

