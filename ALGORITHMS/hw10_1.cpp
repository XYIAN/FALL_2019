    /*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/radix-sort-4-1/submissions/code/1317755231
 * Title: hw10_1.cpp
 * Abstract: This program will conduct radix sort on the given user input 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 11/18/19
 * Version: 1.0 
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

//modified referenced code from https://www.geeksforgeeks.org/radix-sort/
int getMax(vector<int> &v, int n)
{
    int max = v.at(0); 
    for(int i = 1; i < n ; i++)
    {
        if(v.at(i) > max)
        {
            max = v.at(i); 
        }
    }
    return max; 
}

void countSort(vector<int> &v, int n , int exp)
{
    vector<int> output(n); 
    int i ; 
    vector<int>count(10); 

    for(i = 0 ; i < n ; i ++ )//store count occourances 
    {
        count.at((v.at(i)/exp)%10)++; 
    }
    for(i = 1 ; i < 10 ; i ++)//position in output 
    {
        count.at(i) += count.at(i-1); 
    }
    for(i = n - 1 ; i >= 0 ; i--)//build output array
    {
        output.at(count.at( (v.at(i)/exp)%10   ) - 1 ) = v.at(i);
        count.at( (v.at(i)/exp)%10)--; 
    }
    for(i = 0 ; i < n ; i++)//copy array to output 
    {
        v.at(i) = output.at(i); 
    }
}
//end modified referenced functions
void print(int size, vector<int> &v)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << v.at(i) << " "; 
    }
    cout << endl; 
}


//half modified function from above url 
void radixSort(vector<int> &v, int n)
{
    int max = getMax(v, n); 

    for(int exp = 1; (max/exp) > 0 ; exp *= 10)
    {
        countSort(v, n, exp); 
        print(n, v);

    }
    

}

int read()
{
    int size; int fill; 
    cin >> size; 
    vector<int>sortV; 
    
    for(int i = 0 ; i < size; i++)
    {
        cin >> fill; 
        sortV.push_back(fill);
    }

    radixSort(sortV, size); 
    //print(size, sortV); 
    return 0; 
}
//MAIN BEGIN
int main() 
{
    read(); 
}//END MAIN 