/*
	An efficient way to find the proper bounds is to start at the beginning of the array with 
  the bound’s size as ‘1’ and exponentially increase the bound’s size (i.e., double it) until
  we find the bounds that can have the key.
*/

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int 
get(vector<int> &reader, int index) {
	if (index >= reader.size()) {
		return numeric_limits<int>::max();
	}
	return reader[index];
}

static int 
binarySearch(vector<int> &reader, int key, int start, int end) {
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (key < get(reader, mid)) {
			end = mid - 1;
		} else if (key > get(reader, mid)) {
			start = mid + 1;
		} else { // found the key
			return mid;
		}
	}

	return -1;
}

static int 
search(vector<int> &reader, int key) {
	// find the proper bounds first
	int start = 0, end = 1;
	while (get(reader, end) < key) {
		int newStart = end + 1;
		end += (end - start + 1) * 2; // increase to double the bounds size
		start = newStart;
	}

	return binarySearch(reader, key, start, end);
}

int 
main(int argc, char *argv[]) {
  vector<int> reader = {4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
  cout << search(reader, 16) << endl;
  cout << search(reader, 11) << endl;
  reader = {1, 3, 8, 10, 15};
  cout << search(reader, 15) << endl;
  cout << search(reader, 200) << endl;
}

