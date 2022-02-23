/*
 Given an array of integers and a value, determine if there are any two integers in the array whose sum is equal to the given value.
 Return true if the sum exists and return false if it does not.
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool
search(vector<int> &A, int start, int end, int comp) {
  for (int i = start; i <= end; i++) {
     if (A[i] == comp) return true;
  }
  return false;
}

bool 
twoSum(vector<int> &A, int target) {
	for (int i = 0; i < A.size(); i++) {
	  int complement = target - A[i];
	  if (search(A, i+1, (A.size() - 1), complement) == true) {
		  return true;
	  }
	} 
	return false;
}

/*
bool
twoSum(int *A, int size, int val) {
  int i = 0;
  int j = size - 1;
  
  while (i < j) {
    int sum = A[i] + A[j];
    if (sum == val) {
      return true;
    }

    if (sum < val) {
      ++i;
    } else {
      --j;
    }
  }
  return false;
}
*/

int 
main() {
  vector <int> v = {5, 7, 1, 2, 8, 4, 3};
  int test[5] = {3, 20, 1, 2, 7};

  for (int i = 0; i < 5; i++) {
    bool output = twoSum(v, test[i]);
    cout << "find_sum_of_two(v, " << test[i] << ") = " << (output ? "true" : "false") << endl;
  }
  return 0;
}
