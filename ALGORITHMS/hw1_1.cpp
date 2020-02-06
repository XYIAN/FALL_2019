/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/370-hw1-1/submissions/code/1316026056
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will find the min distance between any given set of intergers
      ID : 4444
    DATE : 9/1/19
  VERSION: 4.0
*/

#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <cstdlib>
#include <vector>

int main() 
{
  int input, num, distance , small , big;  
  cin >> input; 
  vector<int> v(input);

  for(int i = 0; i < input; i++)
  {
      cin >> num; 
      //cout << "DEBUG num" << num << endl; 
      v.at(i) = num; 
      //cout << v.at(i) << " "; 
      
  }


  if(v.size() > 1)
  {
    
        small = v.at(0) ;
        big   = v.at(1) ;
        distance = abs(small - big);
        //cout << "  DEBUG small " << small <<"  DEBUG big "<< big;
        
    for(int w = 0 ; w < input; w++)
    {
      //cout << v.at(i) << endl;
      for(int k = w + 1; k < input ; k++)
      {
          if(abs(v.at(k)-v.at(w)) < distance)
          {
            small = v.at(k); 
            big   = v.at(w); 
            distance = abs(small - big);
            
          }

      }
    
    }//end nested
    cout << "Min distance: " << distance<< endl; 
    if(small > big)
    {
      cout << "Two numbers for min distance: " << big << " and " << small<< endl; 
    }
    else 
      cout << "Two numbers for min distance: " << small << " and " << big<< endl;


  }//end if 
  if(v.size()<1)
  {
    return 0; 
  }
  //cout << "error"; 

  
  
}//end main 