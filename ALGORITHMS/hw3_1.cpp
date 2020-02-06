/*
     URL : https://hackerrank.com/contests/cst370-f19-hw3/challenges/palindrome-check-10/submissions/code/1316341424
   TITLE : hw3_1.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will return TRUE or FALSE depending on if the given input is a palendrome 
      ID : 4444
    DATE : 9/15/19
  VERSION: 3.0

*/
#include <iostream> 
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <ctype.h>
using namespace std; 

//prototypea
bool pal(string input);
//end prototype
int main() 
{
  
  string input; 
  getline(cin, input); 
  bool boo = pal(input);
  //cout << pal(input); 
  if(boo)//if true
  {
    cout << "TRUE" ;
  }
  else if(!boo)//if false 
  {
      cout << "FALSE";
  }
    
}//end main------


//function definitions--------
bool pal(string input)
{
    string str = ""; 
  for(int i = 0 ;i < input.length() ; i++)
  {
      //remove all symbols and spaces 
      if(((input[i] >= 'a' && input[i]<='z') || (input[i] >= 'A' && input[i]<='Z') ||( input[i] >= '0' && input[i] <= '9')))
        {
            str += tolower(input[i]); 
            //input[i] = '\0';
        }
  }
  //cout << "debug...str without symbols: " <<str << endl ;

  //test if letters are same
  for(int k = 0 ;k < (str.length())/2 ; k++)
  {
      //cout << "input at[" << k << "]=" << str[k]<<endl; 
      //cout << "input at[" << "length" << "]=" << str[str.length()-1-k]<<endl; 
      if(str[k] != str[str.length()-1-k])
      {
          return false; 
      }
  }
  return true;
}