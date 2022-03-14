#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool
validPalindrome(string &str) {
  int len = str.size();
  if (len == 0) return true;
  int left;
  int right;
  int read = len - 1;
  int write = len - 1;

  while (read >= 0) {
    if ((str[read] >= 'a' &&
         str[read] <= 'z') ||
         (str[read] >= 'A' &&
         str[read] <= 'Z')) {
        str[write] = tolower(str[read]);
      read--;
      write--;
    } else {
      read--;
    }
  }

  left = write + 1;
  right = len - 1;

  while (left <= right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int 
main() {
  string str = {"A man, a plan, a canal: Panama"};
  
  cout << "[" << str << "]" << endl << " is valid palindrome ? : " ;
  string str1 = (validPalindrome(str) == true ? "yes" : "no");
  cout << str1 << endl;
  return 0;
}
