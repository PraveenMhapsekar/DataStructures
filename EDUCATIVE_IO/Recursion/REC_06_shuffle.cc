#include <iostream>
#include <string.h>
#include <string>
#include <bits/stdc++.h> 

using namespace std; 

// Method to shuffle 2*n sized array's elements
void 
shuffleArrayRecursive(int left, int right, vector<int> &arr) { 
	// Base case: return if 2 elements, no shuffle needed
	if (right - left == 1) 
		return; 

	// get middle index of whole array
	int middle = (left + right) / 2; 
  
	// get second half of first array 
	int sh_middle = (left + middle) / 2; 

	// get first half of second array 
	int temp = middle + 1; 

	// swapping elements for subarray
	for (int i = sh_middle + 1; i <= middle; i++) {
		swap(arr[i], arr[temp++]);
  }

	// Pass divided first and second half to the 
  // recursive routine
	shuffleArrayRecursive(left, middle, arr); 
	shuffleArrayRecursive(middle + 1, right, arr); 
} 

void shuffler(vector<int> &a, int n){
	shuffleArrayRecursive(0, n-1, a);
}

int main() { 
  vector<int> a = { 1, 3, 5, 7, 2, 4, 6, 8 }; 

	shuffler(a, a.size()); 

	for (std::vector<int>::iterator  i = a.begin(); i != a.end(); i++) {
		cout << *i << " "; 
  }

  cout << endl;
  
	return 0; 
}


