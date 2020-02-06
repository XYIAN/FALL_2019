/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/apple-collection/submissions/code/1316984428
   TITLE : hw6_1.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : this program will pick the max number of apples out of given input
      ID : 4444
    DATE : 10/15/19
  VERSION: 1.0

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
#include <limits.h>
using namespace std; 

vector<int> sums ; 
// Function to display the array 
void display(vector<int> a, int n) 
{ 
	for (int i = 0; i < n; i++) 
	{ 
		cout << a[i] << " "; 
	} 
	cout << endl; 
} 
void printVector(vector<int> & v , int size)
{
    //print DEBUG loop
    //cout << "PRINTING VECTOR " << endl; 
    for(int print = 0 ; print < size ; print++)
    {
        cout << v.at(print) << " " ;  
        //calculate sum 
    }
    cout << endl; 
    

}

void testApples(vector<int> & apples, int x , vector<int>& arr)
{
    // cout << "DEBUG: vector size: " << apples.size() << endl;
    // cout << "DEBUG: count: " << x << endl;
    //printVector(arr , x); 
    int sum = 0 ; 
    //vector<int> sums; 
    bool test = false; 

    if(apples.size() == 0)
    {
        cout << "error empty" ; 
        return; 
        
    } 
    else if(apples.size() == 1)
    {
        sum += apples[0];
        sums[0] += apples[0];  
    }
    else
    {
        for(int i = 0 ; i < x ; i++)
        {

            if(arr[i] == 1 && test) //if there was a 1
            {
                sum = 0 ; 
                sums.push_back(sum); 
                return; 
            }
            else if(!test && arr[i] == 1)//if there was a 0
            {
                sum += apples[i]; 
                test = true; 
                 
            }
            else
            {
                test = false; 
            }
        }
        sums.push_back(sum); 
    }
    //cout << endl<< " sum : " << sum << endl; 
 
    // cout << "MAX: " << max << endl; 
    // cout << "DEBUG SUM =" << sum << endl; 

}
//CODE REFERENCED FROM https://www.geeksforgeeks.org/generate-all-the-binary-strings-of-n-bits/
// Function to generate all binary strings 
void generateAllBinaryStrings(int n, vector<int> &arr, int i, vector<int> & app) 
{ 
    if (i == n) {
        testApples(app, n ,arr ); 
        //printVector(arr, n); 
        return; 
    } 
    // First assign "0" at ith position 
    // and try for all other permutations 
    // for remaining positions 
    arr[i] = 0; 
    generateAllBinaryStrings(n, arr, i + 1 ,app); 
    // And then assign "1" at ith position 
    // and try for all other permutations 
    // for remaining positions 
    arr[i] = 1; 
    generateAllBinaryStrings(n, arr, i + 1, app); 
} //END REFERENCED CODE

void readApples(int boxCount)
{
    vector<int> boxV; 
    //cout << "DEBUG: vector size will be: " << boxCount << endl;
    for(int i = 0 ; i < boxCount ; i++)
    {
        int pushMe; 
        cin >> pushMe; 
        //cout << "test comment::pushing: " << pushMe ;
        boxV.insert(boxV.begin()+ i , pushMe); 
        //cout << ":: vector at[" << i << "]:"<< boxV.at(i) << endl; 
    }
    //cout <<endl<< "DEBUG: vector size: " << boxV.size() << endl;
    vector<int> vec(boxCount) ; 

    generateAllBinaryStrings(boxCount, vec, 0 , boxV);
    //printVector(boxV, boxCount);

    
    

   

}






//MAIN
int main() 
{
   int size = 0 ; 
   cin >> size; 
    //-----------------------
    readApples(size); 
    //cout << endl; 
    int max = -1; 
    for(int j = 0 ; j < sums.size() ; j++ )
    {
        if(max < sums[j])
        {
            max = sums[j]; 
        }
    }
    cout << "Max Apples: " << max; 



    


}//END MAIN