#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
 *    power 
 *    0   -->
 *    1   --> Tens (0-19, special handling) 
 *    2   --> Hundred
 *    3   --> Thousand      
 *    4   --> Tens Thousand  (0-19, special handling)
 *    5   --> Hunderd Thousand
 *    6   --> Miliion
 *    7   --> Tens Million (0-19, special handling)
 *    8   --> Hunderes Millions
 *    9   --> Billion
 *    10  --> Tens Billion (0-19, special handling)
 *    11  --> Hundreds Billion 
 */

vector<string> ZEROTOTEEN = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> TENS = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> BASE = {"", "", "hundred", "thousand",  "", "", "million", "", "", "billion"};

int carry = 0;

string
printnum(int n, int power) {
   string str;
    int tempNum;
    power++;
    if (n <= 0) {
      return str;
    } else {
			str.append(printnum(n/10, power));
			tempNum = n % 10;
			switch (power) {
				case 1:  // ten
				case 4:  // ten thousand  
				case 7:  // ten million
				case 10: // ten billion
						switch (tempNum) {
								case 0:
										carry = 0;
										break;
								case 1:
										carry = 10; /// 11 to 19, 11-19 thousand, 11-19 million or 11-19 billion
										break;
								default: // 2 - 9 count twnty, thirty , forty... thousand, milliion, billion
									//	printf("%s ", TENS[tempNum]);
                    string tmpString = TENS[tempNum];
                    str.append(tmpString);
										str.append(" ");
										break;
						}
						break;
				case 5:    // hundred thousand
				case 8:    // hundred million
				case 11:   // hundred Billion 
						power = power % 3;  // hundred
				default:    // case 0 [0-19], case 2 [hundred], 3 [thousand], 6 [million], 9 [billion], 
						if ((tempNum + carry )!= 0) {
							//	printf("%s %s", ZEROTOTEEN[tempNum + carry], BASE[power]);
							string tmpString = ZEROTOTEEN[tempNum + carry]; 
							str.append(tmpString);
							str.append(" ");
							tmpString =BASE[power];
							str.append(tmpString);
							str.append(" ");
							carry = 0;
						}
						break;
			}
   }
   return str;
}

#define MAX_NUM 21
int main () 
{
    // Test data
    int n[MAX_NUM] = {0, 1, 10, 11, 99, 100, 101, \
                      110, 113, 123, 190, 999, 1000, \
                      1245, 9999, 10000, 10200, 913913, \
                      999999, 1000000, 1234567890};

    // Test loop
    for (int i = 0; i < MAX_NUM; i++) {
      printf("\n%13d\t", n[i]);
      if (n[i] == 0) {
        printf("zero");       // Handle special case of zero
      } else {    
        string str1 =  printnum(n[i], -1);   // Call print function
        cout << str1 ; //<< endl;
      }
    }

    printf("\n");
    return 0;
}
