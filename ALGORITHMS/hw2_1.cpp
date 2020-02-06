/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/binary-numbs/submissions/code/1316159892
   TITLE : hw2_1.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will dispay all binary numbers up to the given interger 
      ID : 4444
    DATE : 9/4/19
  VERSION: 3.0

*/
#include <iostream> 
#include <cmath>
#include <vector>
using namespace std; 

//function prototypes::   
string binary(int x);
int counter(int num);
//end prototypes 


int main()
{
 int input; 
 cin >> input ; 

 if(input > 100 || input < 0)
 {
   cout << "debug out of range" << endl ; 
   return 0; 
 } //test if between 0-100
 if(input == 0)
 {
     cout << 0; 
 }

 int zeros = counter(input);
 

string output; 
 //cout << "debug zeros:" << zeros << endl; 

 for(int t = 0 ; t  <= input ;t++)
 {
     int z = counter(t);
     int z1 = zeros - z; 
     while(z1 > 0)
    {
        output += "0";
        z1--;
        
    }
    
    output += binary(t);
    cout << endl; 
 }
 
 

 }//END MAIN
 



string binary(int x)
{
  vector<int> v;
   
    while(x > 0)
    {
       v.push_back(x%2) ;
       x/=2; 
    }
    for(int y= v.size()-1 ; y >= 0; y-- )
    {
        cout<< v[y]; 
    }
    string str(v.begin(), v.end());
    return str; 
}

int counter(int num)
{
    int count = 0 ;
    int result; 
    while(num > 0)
    {
       result = num % 2; 
       num/=2; 
       count++;
    }
    return count; 
}


