/*
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
	while(i < j) {
	  if (s[i] != s[j]) {
		  return false;
	  }
	}
	return true;
}

bool
validPalindrome(string &s) {
  int len = s.size();
  if (len <= 2) return true;
  int i = 0;
  int j = len - 1;
  int flag = 0;
  while (i < j) {
    if (s[i] != s[j]) {
      // remove either left or right character and validate
      return (isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1));
    }

    i++;
    j--;
  }

  return true;
}

int
main() {
	string s = "abc" ;
	bool ans = validPalindrome(s);
	cout << s << " ans is " << (ans == 1 ? "true" : "false") << " " << endl;
	s = "cbbcc";
	cout << s << " ans is " << (ans == 1 ? "true" : "false") << " " << endl;
}

