#include <iostream>
#include <string>
using namespace std; 

int totalVowels(string text, int len, int index) 
{ 
  //Write your code here
  int count=0;
  if (len==0){return 0;}
  char single=toupper(text[index]);
  if(single=='A' || single=='E' || single=='I' || single=='O' || single=='U')  
  {  
    count++;
  }
    return count + totalVowels(text,len-1,index+1);
} 

//Function to test your code
int main(){
  cout<<"The string is: Hello World"<<endl;
  cout<<"The total number of vowels in this string are: "<<totalVowels("Hello World",10,0)<<endl;

  cout<<"The string is: STR"<<endl;
  cout<<"The total number of vowels in this string are: "<<totalVowels("STR",3,0)<<endl;

  cout<<"The string is: AEIOUaeiouSs"<<endl;
  cout<<"The total number of vowels in this string are: "<<totalVowels("AEIOUaeiouSs",12,0)<<endl;
}
