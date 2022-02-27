#include <iostream>
#include <vector>
using namespace std; 

/* 
   Utility method, called recursively to collect
   coins from `l` to `r` using the height array
   assuming that h height has already been collected
*/
int 
minimumStepsUtil(vector<int> &height, int l, int r, int h) { 
	// base condition: all coins already collected 
	if (l >= r) {
		return 0; 
	}

	// find minimum height index
	int m = l; 
	for (int i = l; i < r; i++) {
		if (height[i] < height[m]) {
			m = i;
		}
	}

	/* 
    Calculate min steps by: 
		a) collecting all vertical line coins 
				 (total r - l) 
		b) collecting all lower horizontal line coins
				 recursively on left and right segments 
  */
	return min(r - l,  // Vertical
					  	minimumStepsUtil(height, l, m, height[m]) + 
							minimumStepsUtil(height, m + 1, r, height[m]) + 
							height[m] - h); 
} 

/*
  Calls the recursive utility function
  and returns the minimum number of steps
  using height array
*/
int 
minimumSteps(vector<int> height, int N) { 
	return minimumStepsUtil(height, 0, N, 0); 
} 

// Testing minimumSteps() method
int 
main() { 
  vector<int> height = { 2, 1, 2, 5, 1 }; 
	cout << minimumSteps(height, height.size()) << endl; 
	return 0; 
} 
