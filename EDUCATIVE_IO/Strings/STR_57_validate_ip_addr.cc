/*
  Validate given IPv4 and IPv6 address
*/
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
  const string validIPv6Chars = "0123456789abcdefABCDEF";
  const string digits = "0123456789";

  bool isValidIPv4Block(string &block) {
    int num = 0;
    //check length
    if (block.size() > 0 && block.size() <= 3) { // can be max three charactes leading upto 255
      for (int i = 0; i < block.size(); i++) {
        char c = block[i];
        // check value
        if (digits.find(c) == string::npos || 
           (i == 0 && c == '0' && block.size() > 1)) {  // special case: if c is a leading zero
          // c is not digit 
          return false;
        } else {
					num *= 10;
					num += c - '0';
        }
      }
      return (num <= 255 ? true : false);
    }

    return false;
  }

  bool isValidIPv6Block(string &block) {
    //check length
    if (block.size() > 0 && block.size() <= 4) {
      for (int i = 0; i < block.size(); i++) {
        char c = block[i];
         // check value
        if (validIPv6Chars.find(c) == string::npos) {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  string validIPAddress(string IP) {
    stringstream ss(IP);
    string block;

    if (IP.substr(0, 4).find('.') != string::npos) {
      // ipv4 candidate
      for (int i = 0; i < 4; i++) {
				if (!getline(ss, block, '.') || !isValidIPv4Block(block)) { // Getline from stream into string
					return "Neither";
				}
      } 
			return ss.eof() ? "IPv4" : "Neither";
    } else if (IP.substr(0, 5).find(':') != string::npos) {
			// ipv6 candidate
      for (int i = 0; i < 8; i++) {
        if (!getline(ss, block, ':') || !isValidIPv6Block(block)) {
					return "Neither";
        }
      }
      return ss.eof() ? "IPv6" : "Neither";
    }

    return "Neither";
  }
};

int
main() {
  Solution s;

  string IP = "1.2.3.4";
  cout << IP <<  " : " << s.validIPAddress(IP) << endl;

  IP = "1.1.2.3.4";
  cout << IP <<  " : " << s.validIPAddress(IP) << endl;

  IP = "301.2.3.4";
  cout << IP <<  " : " << s.validIPAddress(IP) << endl;

  IP = "255.255.255.255";
  cout << IP <<  " : " << s.validIPAddress(IP) << endl;

  IP = "255.255.255.256";
  cout << IP <<  " : " << s.validIPAddress(IP) << endl;
}
