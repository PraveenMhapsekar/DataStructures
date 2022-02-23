/*
	Search for a given number in a sorted array, with unique elements, 
  that has been rotated by some arbitrary number.
   Return -1 if the number does not exist.
*/

#include <iostream>
#include <vector>

using namespace std;

int 
binary_search(vector<int>& arr, int start, int end, int key) {
  // assuming all the keys are unique.
  if (start > end) {
    return -1;
  }

  int mid = start + (end - start) / 2;

  if (arr[mid] == key) {
    return mid;
  }

  if (arr[start] <= arr[mid] && key <= arr[mid] && key >= arr[start]) {
    // search if key in within start and mid
    return binary_search(arr, start, mid - 1, key);
  } else if (arr[mid] <= arr[end] && key >= arr[mid] && key <= arr[end]) {
    // search if key in mid+1 to end
    return binary_search(arr, mid + 1, end, key);
  } else if (arr[end] <= arr[mid]) {
    // search mid is greter than end! ahha!
    return binary_search(arr, mid + 1, end, key);
  } else if (arr[start] >= arr[mid]) {
    // search start is greater than mid
    return binary_search(arr, start, mid - 1, key);
  }

  return -1;
}

int 
binary_search_rotated(vector<int>& arr, int key) {
  int start = 0;
  int mid = 0;
  int end = arr.size() - 1;

  if (start > end)
    return -1;
    
  while (start <= end) {
    mid = start + (end - start) / 2; 

    if (arr[mid] == key) {
      return mid;
    }

    if (arr[start] <= arr[mid] && key <= arr[mid] && key >= arr[start]) {
      // search if key in within start and mid
      end = mid - 1;
    } else if (arr[mid] <= arr[end] && key >= arr[mid] && key <= arr[end]) {
      // search if key in mid+1 to end
      start = mid + 1;
    } else if (arr[start] <= arr[mid] && arr[mid] <= arr[end] && key > arr[end]) {
//      start = mid + 1; 
    } else if (arr[end] <= arr[mid]) {
      // search mid is greter than end! ahha!
      start = mid + 1;  
    } else if (arr[start] >= arr[mid]) {
      // search start is greater than mid
      end = mid - 1; 
    } else {
      return -1;
    }
  }

  return -1;
}

// Recursive
int 
bbinary_search_rotated(vector<int>& arr, int key) {
  return binary_search(arr, 0, arr.size()-1, key);
}

int main() {
	vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};

	cout<<"Key(3) found at: "<<binary_search_rotated(v1, 3)<<endl;
	cout<<"Key(6) found at: "<<binary_search_rotated(v1, 6)<<endl;
	
	vector<int> v2 = {4, 5, 6, 1, 2, 3};
	
	cout<<"Key(3) found at: "<<binary_search_rotated(v2, 3)<<endl;
	cout<<"Key(6) found at: "<<binary_search_rotated(v2, 6)<<endl;    
}
