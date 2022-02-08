// Find smallest number  among  three array

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverse_array(vector<int> &arr, int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    ++start;
    --end;
  }
}

void rotate_array(vector<int>& arr, int n) {

  int len = arr.size();
  // Let's normalize rotations
  // if n > array size or n is negative.
  n = n % len;
  if (n < 0) {
    // calculate the positive rotations needed.
    n = n + len;
  }

  // Let's partition the array based on rotations 'n'.
  // For example: 1, 2, 3, 4, 5 where n = 2.
  // -> 5, 4, 3, 2, 1
  // -> 4, 5, 3, 2, 1
  // -> 4, 5, 1, 2, 3
  reverse_array(arr, 0, len-1);
  reverse_array(arr, 0, n-1);
  reverse_array(arr, n, len-1);
}

int
main() {
  vector<int> arr = {1, 10, 20, 0, 59, 86, 32, 11, 9, 40};

  cout<<"Array Before Rotation"<<endl;
  for(int i = 0; i < arr.size(); i++)
    cout<<std::to_string(arr[i])+", ";
  cout<<endl;
  
  cout<<"Array After Rotation"<<endl;
  
  rotate_array(arr, 2);
  
  for(int x = 0; x < arr.size(); x++)
    cout<<std::to_string(arr[x])+", ";
  cout<<endl;
}
