// Find maximum of sliding window

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

vector <int>
findMaxSldingWindow(vector<int> &A, int windowSize) {
  vector<int> result;
  queue<int> q;
	int max = INT_MIN;
	int k = 0;

	for (int i = 0; i < windowSize; i++) {
		if (A[i] > max) { 
      max = A[i];
  	}
	}
  result.push_back(i);
  q.push(max);
  cout << "I am here " <<  max << endl;
	for (int i = windowSize; i < A.size(); i++) {
    int tmp = q.front(); q.pop();
		int diff = A[i] - tmp;
    
     cout << "diff " << diff << endl;
    if (diff > 0) { 
	    result.push_back(result[k] + diff);
    } else {
      result.push_back(result[k]);
    }
    k++;
	}

	return result;
}

int 
main() {
 vector<int> A = {1, 2, 3, 4, 3, 2, 1, 2, 5};
 vector<int> ans = findMaxSldingWindow(A, 4);
 for (int i = 0; i < ans.size(); i++) {
   cout << ans[i] << " ";
 }
 cout << endl;
 // cout << ans << endl;
}
