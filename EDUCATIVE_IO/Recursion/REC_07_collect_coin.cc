#include <iostream>
using namespace std; 

// returns minimum of two numbers
int min2(int a, int b){
  return a < b ? a : b;
}

/* 
   Utility method, called recursively to collect
   coins from `l` to `r` using the height array
   assuming that h height has already been collected
*/
int minimumStepsUtil(int l, int r, int h, int height[]) { 
	// base condition: all coins already collected 
	if (l >= r) {
		return 0; 
  }

	// find minimum height index
	int m = l; 
	for (int i = l; i < r; i++) 
		if (height[i] < height[m]) 
			m = i; 

	/* 
    Calculate min steps by: 
		a) collecting all vertical line coins 
       (total r - l) 
		b) collecting all lower horizontal line coins
       recursively on left and right segments 
  */
	return min2(r - l,  // Vertical
			minimumStepsUtil(l, m, height[m], height) + 
			minimumStepsUtil(m + 1, r, height[m], height) + 
			height[m] - h); 
} 

/*
    calls the recursive utility function
    and returns the minimum number of steps
    using height array
*/
int minimumSteps(int height[], int N) { 
	return minimumStepsUtil(0, N, 0, height); 
} 

// Testing minimumSteps() method
int main() { 
	int height[] = { 2, 1, 2, 5, 1 }; 
	int N = sizeof(height) / sizeof(int); 

	cout << minimumSteps(height, N) << endl; 
	return 0; 
} 

