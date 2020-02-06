/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/matching-form/submissions/code/1316524013
   TITLE : hw4_2.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will compare sets of brackets  
      ID : 4444
    DATE : 9/24/19
  VERSION: 2.0

*/

#include <iostream> 
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <ctype.h>
#include <stack>
using namespace std; 


//prototypes 
bool tester(); 

int main() 
{
  bool fill = tester(); 
  //cout << "Tester value =" << fill << endl; 
  if(fill)
  {
      cout << "TRUE";
  } 
  else if(!fill)
  {
      cout << "FALSE";
  }
  else
  {
      cout << endl << "debug error" << endl; 
  }
  
}
/*
if open push
if close and size stack=0 return false 
*/
//function definitions 
bool tester()
{
    stack<char> myStack; 
    string input; 
    getline(cin, input);

    for(int i = 0 ; i < input.length() ; i++)
    {
        if(input[i] == '{' || input[i] == '(' || input[i] == '[')
        {
            myStack.push(input[i]);
            
        }
        else if(input[i] == '}' || input[i] == ')' || input[i] == ']')
        {
            if(myStack.size() > 0)
            {
                if(myStack.top() == '{' && input[i] == '}')
                {
                    myStack.pop(); 
                }
                else if(myStack.top() == '(' && input[i] == ')')
                {
                    myStack.pop(); 
                }
                else if(myStack.top() == '[' && input[i] == ']')
                {
                    myStack.pop(); 
                }
                else
                {
                    return false; 
                }
            }
            else
            {
                return false; 
            }
        }
    }//end for loop 
    if(myStack.size() > 0)
    {
        return false; 
    } 
    else
        return true; 


    
}