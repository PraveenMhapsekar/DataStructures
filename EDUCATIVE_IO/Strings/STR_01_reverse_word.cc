/*
	Here is how the solution works:

	Reverse the string.
		- Traverse the string and reverse each word in place.
		- Let’s apply this solution to our example:

	“The quick brown fox jumped over the lazy dog.”.

	Reverse the string:
	“.god yzal eht revo depmuj xof nworb kciuq ehT”

	Reverse each word in-place:
	“dog. lazy the over jumped fox brown quick The”

*/

#include <iostream>
#include <string>

using namespace std;

void 
reverse_word(string &str, int start, int end) {
  while(start < end ) {
    char tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
    start++;
    end--;
  }
}

void 
reverse_string(string &str) {
  int len = str.size();
  int start = 0;
  int end = len - 1;

  cout << str << endl; 
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  } 
  
  cout << str << endl; 
  start = 0;
  end = 0;
  while (str[end] != '\0') {
    if (str[end] != ' ') {
      end++;
    } else {
      reverse_word(str, start, (end - 1));
      end++;
      start = end;
    }
  }

  reverse_word(str, start, (end - 1));
  cout << str << endl; 
}

int
main() {
  string str("The quick brown fox jumped over the lazy dog");
  reverse_string(str);
  return 0;
}
