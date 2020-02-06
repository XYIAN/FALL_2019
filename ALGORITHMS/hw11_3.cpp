/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/closed-hashing/submissions/code/1318191881
 * Title: hw11_3.cpp
 * Abstract: ; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 12/4/19
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
#include <unordered_map>
using namespace std;

void print(vector<vector<int>> v)
{
     for(int i = 0 ; i < v.size() ; i++)
     {
         for( int j = 0 ; j < v.size() ; i++)
         {
             cout<<v[i][j] << " " ; 
         }
         
     }
     return; 
}



void insert(vector<vector<int>> v, int value)
{
    int size = v.size();  
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            // if()
            // {
            //     v[i][j] = value; 
            // }
            // else if()
            // {

            // }
        }
    }
}

void displayStatus(vector<vector<int>> , int value)
{
    cout << " " << endl ;
}

void search(vector<vector<int>> v , int value)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v.size() ; j++)
        {
            // if()
            // {
            //     //insert 
            // }
            // else if()
            // {
            //     //rehash & insert?
            // }
        }
    }
}

void deleteF(vector<vector<int>> v, int value)
{

}

//begin read function
void read()
{
    vector<vector<int>> v; 
    int size, input, filler; 
    string s ; 
    cin >> size; 
    for(int i = 0 ; i < size; i++)
    {
        for(int j = 0 ; j < size; j++)
        {
            cin >> input; 
            v[i][j] = input; 
        }

    }
    print(v); 

    char answer = 'Y'; 
    string operation; 
    while(answer == 'Y')
    {
 
        if(operation == "insert")
        {
            cin >> filler; 
            insert(v, filler); 
        }
        if(operation == "displayStatus")
        {
            cin >> filler; 
            displayStatus(v, filler); 
        }
        if(operation == "search")
        {
            cin >> filler; 
            search(v, filler); 
        }
        if(operation== "delete")
        {
            cin >> filler ; 
            deleteF(v, filler);
        }

        cout <<endl<< "Would you like to continue?(Y/N): " ; 
        cin >> answer; 
        cout << endl;

    }//end while loop 

    
    return; 
}


//START MAIN 
int  main()
{
    cout << " DEBUG PROGRAM RUNNING : : " << endl ; 
    read(); 

    return 0; 
}
//  END MAIN