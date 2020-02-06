/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/buy-two-one-free/submissions/code/1316497032
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
int calc(); 

int main() 
{
  calc(); 
}

//function definitions
int calc()
{
    //vector<int> vec; 
    int size, sum; 
    cin >> size; 
    int counter = size; 
    vector<int> vec(size); 

    for(int i = 0 ; i < size ; i++)
    {
        cin >> vec[i]; 
    }
    
    sort(vec.begin(), vec.end());
    // for(int print = 0 ; print < vec.size() ; print++)
    // {
    //     cout << vec[print] << " "; 
    // }
    int free = floor((vec.size()*(1.0/3.0))); 
    //cout << free<< endl; 
    for(int i = 0 ; i < size-free ; i++)
    {
        sum += vec[i];    
    }

    cout << sum; 

    return 0; 
} 