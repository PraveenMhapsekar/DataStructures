/*
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

char *
remove_dup(char *str, int size) {
  signed char read = size - 1;
  signed char write = size - 1;
  
  while (read >= 0) {
    if (str[read] != ' ') {
      str[write] = str[read];
      write--;
      read--; 
    } else {
      read--;
    }
  }
  return &str[write];
}

int
main() {
  string str("dab bac");
  // Print Before
  cout << str << endl;
  char *arr = const_cast<char*>(str.c_str());
  int size = str.size();
  remove_dup(arr, size);
  // Print After 
  cout << arr << endl;
  return 0;
}
