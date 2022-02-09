#include <iostream>
#include <string.h>
#include <string>
using namespace std; 

bool
palindromeHelper(char *str, int front, int back) {

	if (front == back) return  true;

	if (str[front] != str[back]) {
		return false;
	}

	return palindromeHelper(str, front + 1, back - 1); 
}

bool
isPalindrome(char *str) {
  return  palindromeHelper(str, 0, strlen(str) - 1);
}

int 
main() {
  char  text[3][20]={"madam","no","dad"};
   
  for (int i = 0; i < 3; i++) {
		int answer = isPalindrome(text[i]);
		if (answer) {
			cout<< "Yes" <<endl;
		} else {
			cout<< "No" <<endl;
		}
	}
}
