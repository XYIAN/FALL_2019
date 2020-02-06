    /*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/alien-alphabet/submissions/code/1317892792
 * Title: hw10_2.cpp
 * Abstract: This program will decipher an alien language and display the characters back in alphbetical order; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 11/18/19
 * Version: 2.0 
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


void print(unordered_map<int, string> &map)
{
    cout << map.at(0); 
    for(int i = 1 ; i < map.size() ; i++)
    {
        cout <<"->" << map.at(i); 
    }
    cout << endl; 

}

void printV(vector<string> v)
{
    cout << "printing vector... : "<<endl ; 
    cout << v.at(0); 
    for(int i = 1 ; i < v.size() ; i++)
    {
        cout << "->"<< v.at(i) ; 
    }
    cout << endl; 
}

bool invalidValue(unordered_map<int, string> map, string check1, string check2)
{
    //value at check2 comes before value at check1
    // unordered_map<int, string>::const_iterator got= map.find(0);
    int one = -1;
    int two = -1;
    for (auto x : map) 
    {
        if(x.second == check1)
        {
            one = x.first;
        }
        if(x.second == check2)
        {
            two = x.first;
        }
    }
    if(one >= 0 && two >= 0 && two < one)
    {
        return true;
    }
    return false;
    
}

bool mapCheck(unordered_map<int, string> map, string check)
{
    for (auto x : map) 
    {
        //cout << x.first << " " << x.second << endl;
        //iterate through the first index
        if(check == x.second)
        {
            return true; //true if item is in map
        }
    }
    return false; //item match not found 
} 
void append(unordered_map<string, int> map )
{
    //maybe?
    
}
unordered_map<int, string> testString(vector<string> v, unordered_map<int, string> map)
{
    //append at end container? populate when values are at end of strings but strings are not at end of input. At end of function, append the values to the map if they are not already in the map. 
    string t1 , t2, t3; 
    int count = 0 ; 
    t3 = "invalid input."; 
    for(int i = 0 ; i < v.size()-1; i++)
    {
        t1 = v.at(i); 
        t2 = v.at(i+1);
        for(int j = 0 ; j < t1.length(); j++)
        {
            //cout << "comparing " << t1[j] << " to " << t2[j] << endl;
            if(t1[j] != t2[j])
            {
                bool insertA = false;
                bool print = true;
                bool insertB = false;
                if(invalidValue(map, t1.substr(j,1), t2.substr(j,1)))
                {
                    cout << t3 << endl;
                    break; 
                }
                if(!mapCheck(map, t1.substr(j,1)))
                {
                    string newt1 = t1.substr(j,1); 
                    //cout << "debug inserting [" << newt1 << "]" <<endl; 
                    map.insert({count , newt1});
                    count++; 
                    insertA = true;
                }
                if(!mapCheck(map, t2.substr(j,1)))
                {
                    string newt2 = t2.substr(j,1); 
                    //cout << "debug inserting [" << newt2 << "]" <<endl; 
                    map.insert({count , newt2});
                    count++; 
                    insertB = true;
                }
                if((insertA && insertB) || (mapCheck(map, t1.substr(j,1)) && insertB))
                {
                    break;
                }
            }
            else
            {
                if(!mapCheck(map, t1.substr(j,1)))
                {
                    map.insert({count , t1.substr(j,1)});
                    count++;
                }
            }
        }
    }
    if(!invalidValue(map, t1, t2))
        print(map); 
    return map;
}

//READ INPUT AND  STORE  
void read()
{//input is assumed sorted 
    int size; cin >> size; 
    string f2, f1; 
    unordered_map<int, string> map;      
    vector<string> testV; 

    int count = 0 ; 
    for(int i = 0 ; i < size; i++)
    {
        cin >> f1; 
        
        testV.push_back(f1); 
    }

    cout << endl; 
    testString(testV, map); 
      
}


//begin main 
int main() 
{
    read(); 
    return 0 ; 
}
//END MAIN

/*
===INPUTS===
3
caa
aaa
aab

9
caa
eeb
eef
aaa
aab
deed
deeb
def
daad

3
aaa
bbb
abab

5
aab
bba
ddd
cca
ccc

5
aab
bba
ddd
ccc
cca


===OUTPUT===

c->a->b

c->e->a->d->b->f

Invalid input.

a->b->d->c

Invalid input.

*/