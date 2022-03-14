/*
  Leetcode : Read N Characters Given Read4
  Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// int read4(char *buf4);
using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
      char iBuf[4]; // Internal Buffer
      char *iBufPtr = iBuf; // Internal Buffer Pointer
      int iBufCnt = 0; // Internal Buffer Counter
      int rBufCnt = 0; // Return Buffer Pointer
      
      if (n == 0) {
        return n;
      }  

      while (rBufCnt < n) {
        if (iBufCnt == 0) {
          int cnt = read4(iBuf);
          if (cnt == 0) { 
            cout << "read buffer empty " << endl;
            return rBufCnt; 
          } else {
            iBufCnt += cnt;
          }   
        }  else {
          if (n <= iBufCnt) {
            memcpy(buf+rBufCnt, iBufPtr, n); 
            iBufCnt -= n;
            iBufPtr += n;
            rBufCnt += n;
          } else {
            memcpy(buf+rBufCnt, iBufPtr, iBufCnt);
            rBufCnt += iBufCnt;
            iBufCnt = 0;
            iBufPtr = iBuf;
          }
        }   
      } // end of while
      return n;
    }
};
