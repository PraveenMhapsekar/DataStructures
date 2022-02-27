#include <iostream>
#include <vector>
using namespace std; 

bool
palindromeHelper(string &str, int front, int back) {
	if (front >= back) return  true;

	if (str[front] != str[back]) {
		return false;
	}

	return palindromeHelper(str, front + 1, back - 1); 
}

bool
isPalindrome(string &str) {
  return  palindromeHelper(str, 0, str.size() - 1);
}

int 
main() {
  vector<string> text = {"madam", "no", "abcdcba", "abccba"};   

  for (int i = 0; i < text.size(); i++) {
		int answer = isPalindrome(text[i]);
		if (answer) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
  return 0;
}
