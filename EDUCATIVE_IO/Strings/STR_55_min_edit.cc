/*
*/
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// int read4(char *buf4);
using namespace std;

bool
isOneEditDistance(string s, string t) {
  int ns = s.length();
  int nt = t.length();
  #if 0
  if ((ns == 1) && (nt == 1)) {
     if (s[0] == t[0]) return false;
     return true;
  } 
  #endif
  // Ensure that s is shorter than t.
  if (ns > nt) {
    return isOneEditDistance(t, s); 
  }

  // The strings are NOT one edit away distance  
  // if the length diff is more than 1.
  if (nt - ns > 1) {
    return false;
  }

  for (int i = 0; i < ns; i++) {
    if (s[i] != t[i]) {
      string tmp;
      if (ns == nt) {
        // if strings have the same length
        tmp = s.substr(i + 1); 
      } else {
        // if strings have different lengths
        tmp = s.substr(i); 
      }   
      return (tmp.compare(t.substr(i + 1)) == 0 ? true : false);
    }   
  }

  // If there is no diffs on ns distance
  // the strings are one edit away only if
  // t has one more character. 
  return (ns + 1 == nt);
}  

int
main() {
 string s = "abcd";
 string t = "abcde";
 cout << s << endl;
 cout << t << endl;
 cout << "one edit way? : ";
 cout << (isOneEditDistance(s, t) == 1 ? "yes" : "no") << endl;

}
