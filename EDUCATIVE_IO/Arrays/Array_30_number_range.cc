using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    result.first = search(arr, key, false);
    if (result.first != -1) {  // no need to search, if 'key' is not present in the input array
      result.second = search(arr, key, true);
    }
    return result;
  }

 private:
  // modified Binary Search
  static int search(const vector<int> &arr, int key, bool findMaxIndex) {
    int keyIndex = -1;
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {  // key == arr[mid]
        keyIndex = mid;
        if (findMaxIndex) {
          start = mid + 1;  // search ahead to find the last index of 'key'
        } else {
          end = mid - 1;  // search behind to find the first index of 'key'
        }
      }
    }
    return keyIndex;
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}
