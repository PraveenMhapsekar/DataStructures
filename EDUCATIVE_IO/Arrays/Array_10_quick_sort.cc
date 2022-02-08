/*
*/
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Below partition is using Hoare's algorithm.
int partition(int arr[], int low, int high) {
  int pivot_value = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (i <= high && arr[i] <= pivot_value) 
      i++;
    while (arr[j] > pivot_value)
      j--;

    if (i < j) {
      std::swap(arr[i], arr[j]);
    }   
  }

  arr[low] = arr[j];
  arr[j] = pivot_value;

  return j;
}

void 
quick_sort_rec(int arr[], int low, int high) {
  if (high > low) {
    int pivot_index = partition(arr, low, high);
    quick_sort_rec(arr, low, pivot_index - 1);
    quick_sort_rec(arr, pivot_index + 1, high);
  }
}

void quick_sort(int arr[], int size) {
  quick_sort_rec(arr, 0, size - 1);
}

int main()
{
  int a[] = {55, 23, 26, 2, 18, 78, 23, 8, 2, 3};
    
  cout << "Before Sorting" << endl;
  for (int i : a) {
    cout << i << ", ";
  }
  cout << endl;
  
  quick_sort(a, sizeof(a)/sizeof(int));
  
  cout << endl << "After Sorting" << endl;
  for (int i : a) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
