/*
  The runtime complexity of this solution is polynomial, O(n^2)
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int 
find_palindromes_in_sub_string(const string& input, int j, int k) {
  int count = 0;
  for (; j >= 0 && k < input.length(); --j, ++k) { // Scan till leftend(0) and rightend(len -1) of the array
    if (input[j] != input[k]) {      
      break;
    } 
    cout << input.substr(j, k - j + 1) << endl; // input.sunstr(position, len)
    ++count;
  }
  return count;
}

int
find_all_palindrome_substrings(const string& input) {
  int count = 0;
  for (int i = 0; i < input.length(); ++i) {    
    count += find_palindromes_in_sub_string(input, i - 1, i + 1); // Odd (-1 1) (0 2) (1 3) (2 4) (3 5)
    count += find_palindromes_in_sub_string(input, i, i + 1); // Even (0 1) (1 2) (2 3) (3 4) 
  }
  return count;
}

int 
main() {
  string str = "aabbbaa";
  cout << "Total palindrome substrings: "  << find_all_palindrome_substrings(str) << endl;
  return;
}
