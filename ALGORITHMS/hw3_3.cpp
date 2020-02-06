/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/adjacency-list/submissions/code/1316342108
   TITLE : hw3_3.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will convert user input of weighted graph to adjacency list style  
      ID : 4444
    DATE : 9/17/19
  VERSION: 1.0
*/
#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;


//prototypes::::::::
void graph(int v, int e);
//end prototypes::::

int main()
{
    int verticies, edges; 
    cin >> verticies >> edges; 
    graph(verticies, edges);

}//end main

//funtion definitions::::::::
void graph(int v, int e)
{
    //cout <<"vert"<< v << " edge" << e << endl ; 
    bool twoD[v][e];
    int in1, in2; 
    for(int  i = 0 ; i < e; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            twoD[i][j] = false;
            //cout << twoD[i][j] << " "; 
        }    
        //cout << endl; 
    }

    for(int z = 0 ; z < e ; z++)
    {
        cin >> in1 >> in2;
        twoD[in1][in2] = true;  
    }
    //print
    
    for(int  i = 0 ; i < e; i++)
    {
        if(i < v)
        {
            cout << i; 
        }
        for(int j = 0 ; j < v ; j++)
        {
            
            if(twoD[i][j])
            {
                cout << "->" <<j; 
            }
            //cout << twoD[i][j] << " "; 
        }    
        cout << endl; 
    }

    if(e == 0)
    {
        for(int i = 0 ; i < v; i++)
        {
            cout << i << endl; 

        }
    }

    
}



//end funtion definitions::::