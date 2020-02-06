/*
 * HackerRank link:https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/knapsack-7-1/submissions/code/1318375981  
 * Title: hw12_1.cpp
 * Abstract:this program will take user input of items and bag size. Next it will compute the total ammount of large value items you can add to the bag along with final step and items picked ; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 12/12/19
 * Version: 3.6 
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


int max(int a, int b) { return (a > b)? a : b; } 

void printV(vector<pair<int, int>> v)
{
    for(int i = 0 ; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl; 
    }
}

void knapSack(vector<pair<int, int>> v, int size)
{
    int maxValue = 0;
    vector<int> items;
    int myArr[v.size()+1][size+1];
    vector<vector<int>> resultVect;
    for(int i = 0 ; i <= v.size(); i++)
    {
        for(int j = 0 ; j <= size; j++)
        {
            //compare items between row and column 
            if(i == 0 || j == 0)
            {
                myArr[i][j] = 0; //building the outer edge of 0s in the matrix
            }
            else if(v[i-1].first <= j)
            {
                myArr[i][j] = max(v[i-1].second + myArr[i-1][j-v[i-1].first], myArr[i-1][j]);
            }
            else 
            {
                myArr[i][j] = myArr[i-1][j]; //same as above element in matrix
            }
        }
    }
    
    if(myArr[v.size()][size] != 0)
    {
        maxValue = myArr[v.size()][size];
    }

    // for(int i = 0; i <= v.size(); i++)
    // {
    //     for(int j = 0; j <= size; j++)
    //     {
    //         cout << myArr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    //output formatting ::
    cout << "Final step: "; //print result vector here 
    for(int i = 0; i <= size; i++)
    {
        cout << myArr[v.size()][i] << " " ;//LAST ROW IN MATRIX 
    }
    cout << endl;
    cout << "Max Value: " << maxValue << endl; //
    
    cout << "Items: ";
    int topChecker = maxValue;
    int tempSize = size;
    for(int i = v.size(); i > 0 && topChecker > 0; i--)
    {
        if(topChecker != myArr[i-1][tempSize])
        {
            items.push_back(i);
            topChecker = topChecker - v[i-1].second;
            tempSize = tempSize - v[i-1].first;
        }
    }
    reverse(items.begin() , items.end()); //output formatting
    for(int i = 0 ; i < items.size(); i++)
    {
        cout    << items[i] << " " ;
        
    } 
}//END KNAPSACK FUNCTION ::::::::::::::::::::::::::::::::::


void read()//read matrix
{
    int x = 0;
    int y = 0;
    int items;
    int size;

    vector<pair<int, int>> matrix;

    cin >> items;//number of items 
    cin >> size;//total sack size 
    for(int i = 0; i < items; i++)
    {
        cin >> x;
        cin >> y;
        matrix.push_back(pair<int, int> (x, y));
    }
    //cout << endl;
    knapSack(matrix, size);
    return;
}


int main()
{
    read();
    return 0; 
}

/*
INPUT
4
5
2 12
1 10
3 20
2 15

1
1
10 10

7
7
1 7
2 6
3 5
4 4
5 3
6 2
7 1




OUTPUT::::::::::::::::::::

Final step:0 10 15 25 30 37
Max value:37
Items:1 2 4

Final step:0 0
Max value:0
Items:

Final step: 0 7 7 13 13 13 18 18
Max value:18
Items:1 2 3


*/


5371 south federal circle, littleton colorado 80123 apt q308
http://lefthandbrewing.com/beers/flamingo-dreams-nitro/
https://crazymountainbrewery.com/beer/horseshoes-hand-grenades/