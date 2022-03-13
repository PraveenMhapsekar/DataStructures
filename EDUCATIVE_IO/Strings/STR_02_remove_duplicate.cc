/*
	Given a string that contains duplicate occurrences of characters, remove the duplicate occurrences.
	The string is passed by reference. So you don’t need to return anything.
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void
remove_dup(char *str) {
  unordered_set <char> set;
  char *rPtr =str;
  char *wPtr = rPtr;

  if (rPtr == nullptr) return;

  while (*rPtr != '\0') {
    if (set.find(*rPtr) == set.end()) {
       *wPtr = *rPtr;
       set.insert(*rPtr);
       ++wPtr;
    }
    ++rPtr;
  }
  *wPtr = '\0';
  return;
}

int
main() {
  string str("dabbac");
  // Print Before
  cout << str << endl;
  char *arr = const_cast<char*>(str.c_str());
  remove_dup(arr);
  // Print After 
  cout << arr << endl;
  return 0;
}
