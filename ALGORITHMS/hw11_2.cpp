     /*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-collection-1-1/submissions/code/1318192096
 * Title: hw11_2.cpp
 * Abstract:THIS PROGRAM WILL travedrse a matrix map  ; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 12/1/19
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

void print(vector<vector<int>> v)
{
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

bool greatest(vector<vector<int>> v, pair<int, vector<pair<int, int>>> firstPair, pair<int, vector<pair<int, int>>> secondPair)
{
    if(firstPair.first > secondPair.first)//firstpair has more coins
    { //make sure the first pair also makes it all the way to the end of the matrix
        return find(firstPair.second.begin(), firstPair.second.end(), pair<int, int> (v.size()-1, v[v.size()-1].size()-1)) != firstPair.second.end();
    }
    else //second pair has more coins
    {
        return !(find(secondPair.second.begin(), secondPair.second.end(), pair<int, int> (v.size()-1, v[v.size()-1].size()-1)) != secondPair.second.end());
    }
}

pair<int, vector<pair<int, int>>> max(vector<vector<int>> v,int row, int col, int sizeRows)
{
    vector<pair<int, int>> coords;
    pair<int, vector<pair<int, int>>> sumRight(0, coords);
    pair<int, vector<pair<int, int>>> sumDown(0, coords);
    int sizeCols = v[row].size()-1;
    // cout << "Row: " << row << " Col: " << col  << " SizeRows: " << sizeRows << " SizeCols: " << sizeCols << endl;
    if(row >= sizeRows && col >= sizeCols) //at the end of the matrix
    {
        coords.push_back(pair<int, int>(row, col));
        pair<int, vector<pair<int, int>>> myPair (v[row][col], coords);
        return myPair;//return value
    }
    else if(row == sizeRows && col < sizeCols && v[row][col+1]!= 2)//can only go right
    {
        sumRight = max(v, row, col+1, sizeRows);
        sumRight.first += v[row][col];
        sumRight.second.push_back(pair<int, int>(row, col));
    }
    else if(row < sizeRows && col == sizeCols && v[row+1][col]!= 2)//can only go down
    {
        sumDown = max(v, row+1, col, sizeRows);
        sumDown.first += v[row][col];
        sumDown.second.push_back(pair<int, int>(row, col));

    }
    //can go either right or down
    //check right
    if(col < sizeCols && row < sizeRows && v[row][col+1]!= 2)
    {
        sumRight = max(v, row, col+1, sizeRows);
        sumRight.first += v[row][col];
        sumRight.second.push_back(pair<int, int>(row, col));
    }

    //check down
    if(row < sizeRows && col < sizeCols && v[row+1][col]!= 2)
    {
        sumDown = max(v, row+1, col, sizeRows);
        sumDown.first += v[row][col];
        sumDown.second.push_back(pair<int, int>(row, col));
    }
    
    return (greatest(v, sumDown, sumRight))? sumDown:sumRight;
}

void printPairs(vector<pair<int, int>> v)
{
    for(int i = v.size()-1; i > 0; i--)
    {
        cout << "(" << v[i].second+1 << "," << v[i].first+1 << ")->";
    }
    cout << "(" << v[0].second+1 << "," << v[0].first+1 << ")" << endl;
}

int checker(vector<vector<int>> v)//check coins 
{
    int size = v.size(); 
    if(size == 0)
    {
        return 0;
    } 
    pair<int, vector<pair<int, int>>> ofBalls = max(v, 0, 0, size-1);
    cout << "Max coins:" << ofBalls.first << endl;
    cout << "Path:";
    printPairs(ofBalls.second);
    return 0; 
}

void read()
{
    int x = 0;
    int y = 0;
    vector<vector<int>> matrix;

    cin >> x;
    cin >> y;
    for(int i = 0; i < y; i++)
    {
        vector<int> row{};
        int value;
        for(int j = 0; j < x; j++)
        {
            cin >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    checker(matrix);
    return; 
 
}



//BGEIN MAIN 
int main()
{
    //cout << "Hello, program now running.. "  << endl; 
    read(); 
    //cout << endl << "Program ended.. Goodbye!" << endl; 

}
// END MAIN 


/*
INPUT---------------

4 4
0 2 1 1
0 1 2 1
0 0 1 2
1 2 0 1

3 2
1 2 1
1 1 1

4 2
0 1 0 0
1 1 2 0

5 5
1 0 1 1 1
1 1 0 0 0
0 1 1 0 1
1 0 1 1 0
1 0 0 1 0


OUTPUT---------------

Max coins:3
Path:(1,1)->(1,2)->(2,2)->(2,3)->(3,3)->(3,4)->(4,4)

Max coins:4
Path:(1,1)->(1,2)->(2,2)->(3,2)

Max coins:1
Path:(1,1)->(2,1)->(3,1)->(4,1)->(4,2)

Max coins:8
Path:(1,1)->(1,2)->(2,2)->(2,3)->(3,3)->(3,4)->(4,4)->(4,5)->(5,5)




*/