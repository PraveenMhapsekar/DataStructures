/*
	RunTime Complexity : O(nlog(n))
	Memory  Complexity : O(log(n)) 
 */

#include <iostream>
#include <vector>
using namespace std;

/* Below partition is using Hoare's algorithm. */
int
partition(vector<int> &arr, int low, int high) {
  int pivot_value = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (i <= high && arr[i] <= pivot_value) {
      i++;
    }

    while (arr[j] > pivot_value) {
      j--;
    }

    if (i < j) {
      swap(arr[i], arr[j]);
    }   
  }

  arr[low] = arr[j];
  arr[j] = pivot_value;

  return j;
}

/* */
void 
quick_sort_rec(vector<int> &arr, int low, int high) {
  if (high > low) {
    int pivot_index = partition(arr, low, high);
    quick_sort_rec(arr, low, pivot_index - 1);
    quick_sort_rec(arr, pivot_index + 1, high);
  }
}

void 
quick_sort(vector<int> &arr) {
  quick_sort_rec(arr, 0, (arr.size() - 1));
}

int 
main() {
  vector<int> A = {55, 23, 26, 2, 18, 78, 23, 8, 2, 3};
    
  cout << "Before Sorting" << endl;
  for (int i : A) {
    cout << i << ", ";
  }
  cout << endl;
  
  quick_sort(A);
  
  cout << endl << "After Sorting" << endl;
  for (int i : A) {
    cout << i << ", ";
  }
  cout << endl;

  return 0;
}
