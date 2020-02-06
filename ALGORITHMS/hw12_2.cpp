/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/floyd-all-pairs-shortest-paths/submissions/code/1318375801
 * Title: hw12_2.cpp
 * Abstract:This program will take user input of size and matrix and preform floyds algorithm with the final step matrix as return result ; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 12/12/19
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

void print(vector<vector<int>> v)
{
    //cout << "debug print function hit ... with size " << v.size() << endl; 
    cout << endl;
     for(int i = 0 ; i < v.size() ; i++)
     {
         for( int j = 0 ; j < v[i].size() ; j++)
         {
             cout<<v[i][j] << " " ; 
         }
         cout << endl;
     }
     return; 
}

void floydsAlgorithm(vector<vector<int>> matrix) //preform floyds on given matrix
{
    int size = matrix.size();
    vector<vector<int>> distances;
    for(int i = 0; i < size; i++)
    {
        vector<int> v;
        distances.push_back(v);
        for(int j = 0; j < size; j++)
        {
            distances[i].push_back(matrix[i][j]);
        }
    }
    //cout << endl << "debug distances before floyd warshalls: "; 
    //print(distances);
    
    if(size == 0)
    {
        //cout << "debug exiting size == 0" << endl; 
        return;
    }
    for(int i = 0  ; i < size; i++)
    {
        for(int j = 0 ; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {

                //recurrence relation
                //check for -1
                //CHECK LOOP CONDITIONS 
                
                if(distances[j][k] >= 0 && distances[j][i]+distances[i][k] < distances[j][k] && distances[j][i] >= 0 && distances[i][k] >= 0)
                {
                    //cout << "DEBUG: 1" << endl ; 
                    distances[j][k] = distances[j][i] + distances[i][k];
                }
                else if(distances[j][k] == -1 && distances[j][i]+distances[i][k] >= 0  && distances[j][i] >= 0 && distances[i][k] >= 0)
                {
                    //cout << "DEBUG: 2" << endl;
                    distances[j][k] = distances[j][i] + distances[i][k];
                }
                
                
            }
            //int max = max(matrix[i][j] , matrix[i][j]); 
        }
    }
    //cout << endl << "debug distances after floyd warshalls: "; 
    print(distances);
    
}

 
void read()
{
    int x = 0;
    int y = 0;
    vector<vector<int>> matrix;

    cin >> x; y = x; 
    //cin >> y;
    for(int i = 0; i < y; i++)
    {
        vector<int> row{};
        int value;
        
        //cout << "debug case 1 hit" << endl; 
        for(int j = 0; j < x; j++)
        {
            cin >> value;
            if(value == -1)
            {
                //cout << " debug -1 == infinity" << endl; 
            }
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    floydsAlgorithm(matrix) ;
    return; 
 
}




//start main 
int main()
{
    //cout << " debug program running.." << endl << endl; 

    read();

    //cout << "debug program ended; " << endl; 
}
//end main 

/*
INPUT 
4
0 -1 3 -1
2 0 -1 -1
-1 7 0 1
6 -1 -1 0

3
0 2 -1
-1 0 2
2 -1 0

OUTPUT
0 10 3 4
2 0 5 6
7 7 0 1
6 16 9 0

0 2 4
4 0 2
2 4 0


*/