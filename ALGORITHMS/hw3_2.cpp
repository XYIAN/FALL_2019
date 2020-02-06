/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/equal-groups/submissions/code/1316396074
   TITLE : hw3_2.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will take size and set of int from user input and display the equivilent set if any  
      ID : 4444
    DATE : 9/17/19
  VERSION: 5.0

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
using namespace std; 

//prototypes::::::::
string binary(int x);//convert binary without leading zeros 
vector<int> run(vector<int>& v1, string inp); //find equal set if any(unfinished)
//end prototypes::::

int main()
{
      
    int input;
    cin >> input; 
    int size = input; 
    vector<int> inputVector ;
    //cin nums into vector
    string fill; 
    int fill1;  
    
    for(int y = 0 ; y < input ; y++)
    {
        cin >> fill1; 
        inputVector.push_back(fill1);

    }
     
        
//(pow(2, input)-1)/2
    for(int k = 0 ; k < (pow(2, input)-1)/2; k++)
    {
        string binaryString = binary(k);
        string zero = ""; 
        int zeros = size - binaryString.length();
        for(int i = 0 ; i < zeros;i++)
        {
            zero +=   "0"  ;

        }//end print zeros
        binaryString = zero + binaryString; 
        //cout << binaryString << endl; 
        //cout << binaryString << endl;
        vector<int> v = run(inputVector, binaryString);

        if(v.size() > 0)
        {
            cout << "Equal Set: " ;
            for(int i = 0; i < v.size() ; i++)\
            {
                cout << v[i] << " "; 
            }

            return 0; 
        }
        /*
        for(int num : v)
        {
            cout << num << " ";
        }
        cout << endl ;
        */
    }
    cout << "Equal Set: 0";

    
    

    /*
    cout << "6:" <<binary(6) << endl;
    // needed for every binary string 
    vector<int> v = run({2, 3, 7, 8}, "0110");
    for(int num : v)
    {
        cout << num << " ";
    }
    cout << endl ; 
    */
    
}//end main

//funtion definitions::::::::
string binary(int x)
{
    //int userInput;
    //cin >> userInput; 
    string s;  
    while(x > 0)
    {
        s = to_string(x%2) + s ;
        x/=2; 
    }
    return s; 
}//END BINARY

vector<int> run(vector<int>& v1, string inp)//determine equal set?
{
    

    vector<int> set1(0) ; 
    vector<int> set2(0) ;
    int sum1 = 0 ; 
    int sum2 = 0 ; 

    for(int i = 0 ; i < v1.size() ; i++)
    {
        if(inp[i] == '0')
        {
            sum1 += v1[i];
            set1.push_back(v1[i]); 
            
        }
        else if(inp[i] == '1')
        {
            sum2 += v1[i];
            set2.push_back( v1[i]); 
        }
        
    } 
    
    if( sum1 != sum2)
    {
        return vector<int>();//empty vector 
    }
    



    if(set1.size()> 0 )
    {
        sort(set1.begin() , set1.end());

    }
    if(set2.size() > 0)
    {
        sort(set2.begin() , set2.end());
    }
    if(sum1 == sum2)
    {
        if(set1[0] > set2[0])
        {
            return set2;
        }
        return set1; 
    }
    
return vector<int>() ; 
    

    
    

}//end run
//end funtion definitions::::