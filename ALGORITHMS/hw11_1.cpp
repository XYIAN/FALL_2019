     /*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-row/submissions/code/1318190644
 * Title: hw11_1.cpp
 * Abstract: This program will take input from a user to solve the coin counting problem; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 12/1/19
 * Version: 3.0 
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
#include <unordered_map>
using namespace std;

void printV(vector<int> V) 
{
    int size = V.size() ; 
    for (int i = 0  ; i  < size; i++ )
    {
        cout<< "vector.at(" << i << ")" << "=" << V.at(i) << endl; 
    }
}



//return pair : (sum, <elements>)
pair<int, vector<int>> max(vector<int> vec, int current, int size, int previous)
{
    if(current >= size) // all elements of the vector have been processed
    {
        return pair<int, vector<int>> (0, {});
    }

    // cout << "Val: " << vec[current] << " Current: " << current << " Previuous: " << previous << endl;
    pair<int , vector<int>> excl = max(vec, current+1, size, previous);
    pair<int , vector<int>> incl (0, {});
    
    //test previous element to make sure it is not adjacent when including it
    if(previous + 1 != current)
    {
        // cout << "First: " << incl.first << " Current: " << current << " Previuous: " << previous <<endl;
        incl = max(vec, current + 1, size, current);
        incl.first += vec[current];
        incl.second.push_back(current+1);
    }
    
    return (excl.first > incl.first)? excl : incl ; 
}

void printVec(vector<int> v)
{
    for(int i = v.size()-1; i >=0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> coinCheck(vector<int> V)
{
    int size = V.size();
    vector<int> returnVec;
    if(size == 0)
    {
        returnVec.push_back(0);
    }
    else if (size == 1)
    {
        returnVec.push_back(1);
    }
    else
    {
        pair<int, vector<int>> ofTits = max(V, 0, size, INT_MIN);
        cout << "Best set:";
        printVec(ofTits.second);
        cout << "Max value:" << ofTits.first << endl;
    }
    return returnVec;
}//end coinCheck


void read()
{
    int coinCount ; cin >> coinCount; //first num input
    //cout << "DEBUG:: coin count==" << coinCount << endl; 
    int filler; 
    
    vector<int> V; 
    for(int i = 0 ; i < coinCount ; i++)
    {
        cin >> filler;
        V.push_back(filler) ; 
    }
    int size = V.size()%coinCount;
    coinCheck(V); 
    
}
//end read function

//begin main
int main()
{
    read();
}
//end main 

/*
INPUT:
6
5 1 2 10 6 2

3
1 2 3


OUTPUT:
Best set:1 4 6
Max value:17

Best set:1 3
Max value:4


*/