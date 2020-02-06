/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/intersection-4/submissions/code/1316035720
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will find the intersection of any given pair of ints
      ID : 4444
    DATE : 9/4/19
  VERSION: 1.0

*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
  int num, 
      right, 
      left; 
  
  int max = INT_MIN; 
  int min = INT_MAX;

  cin >> num; 
  if(num < 1)
  {
    cout << -1;
    return 0; 

  }
  
  for(int i = 0 ; i < num ; i++)
  {
    cin >> left >> right;
    //cout << "debug: you entered.. RIGHT:" << right << "   LEFT:" << left << endl << endl;

    if(left > max) 
    {
      
      max = left; 
      //cout << "DEBUG left:" << left << endl;
    }

    if(right < min)
    {
      min = right; 
      //cout << "DEBUG right:" << right << endl;
    }
    



  }//end for
      if(max > min)
    {
      cout << "-1";

    }
    else
      cout << max << " " << min; 
  
  




  

  

  
}