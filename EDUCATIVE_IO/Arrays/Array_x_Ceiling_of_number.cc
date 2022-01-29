using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    if (key > arr[end]) return -1;

    while(start <= end) {
      int mid = start + (end - start) / 2;

      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
         start = mid + 1;
      } else {
          return mid;
      }
    }
    return start;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 6}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}

