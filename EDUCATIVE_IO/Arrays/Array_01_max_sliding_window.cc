/*
  Given a large array of integers and a window of size W, 
  find the current maximum value in the window as the window slides through the entire array.
  Runtime Complexity #
		The runtime complexity of this solution is linear, O(n).
	Memory Complexity #
		The memory complexity of this solution is linear, O(W) where W is the window size in this case.
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

vector <int>
findMaxSldingWindow(vector<int> &A, int windowSize) {
  vector<int> result;
  deque<int> window;

	for (int i = 0; i < windowSize; i++) {
		while (!window.empty()  && (A[i] >= A[window.back()])) { 
      window.pop_back();
  	}
    window.push_back(i);
	}

  result.push_back(A[window.front()]);

	for (int i = windowSize; i < A.size(); i++) {
    cout << "front : " <<  window.front() << " back : " << window.back() <<endl;
    // remove all numbers that are smaller than current number
    // from the tail of list
		while (!window.empty() && A[i] >= A[window.back()]) {
			window.pop_back();
		}

		// remove first number if it doesn't fall in the window anymore
		if(!window.empty() && window.front() <= i - windowSize ) {
			window.pop_front();
		}

		window.push_back(i);
		result.push_back(A[window.front()]);
  }

  return result;
}

int 
main() {
 vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 for (int i = 0; i < A.size(); i++) {
   cout << A[i] << " ";
 }
 cout << endl;
 vector<int> ans = findMaxSldingWindow(A, 3);
 for (int i = 0; i < ans.size(); i++) {
   cout << ans[i] << " ";
 }
 cout << endl;

 A = {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67};
// {10, 9, 23, 23, 34, 56, 67, 67, 67, -1, -2, 9, 10, 34, 67}
 ans = findMaxSldingWindow(A, 3);
 for (int i = 0; i < ans.size(); i++) {
   cout << ans[i] << " ";
 }
 cout << endl;
}
