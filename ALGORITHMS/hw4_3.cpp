/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/tsp-2-1/submissions/code/1316571859
   TITLE : hw4_3.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will sove small tsp porblems 
      ID : 4444
    DATE : 9/24/19
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

//prototypes::::::
void display(int a[], int n) ;
void find_permutations(int a[],int ve) ;
void graph() ;
int find(string inn , string arra[], int s);
//end prototypes

// Driver code 
int main() 
{ 
    
     graph();
    /*
	int a[] = {1, 2, 3}; 
	int array_size = 3; 

	cout << "========= Permutations =========\n"; 
	find_permutations(a, array_size);
	cout << "========= Done =========" << endl;

	return 0; 
    
4
Monterey
LA
SF
SD
12
Monterey LA 2
Monterey SD 7
Monterey SF 5
LA Monterey 2
LA SF 8
LA SD 3
SF Monterey 5
SF LA 8
SF SD 1
SD Monterey 7
SD LA 9
SD SF 1

    */
    
} 

// Function to display the array 
void display(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) 
	{ 
		cout << a[i] << " "; 
	} 
	cout << endl; 
} 

// Function to find the permutations 
void find_permutations(int a[],int ve ) 
{ 
	// Sort the given array first.
	sort(a, a + ve); 

	// Find all possible permutations 
	do 
	{ 
		display(a, ve); 
	} while (next_permutation(a, a + ve)); 
} 

void graph()
{
    int saveSum = INT_MAX ; 
    int v, e;
    int sum = 0 ; 
    cin >> v ;  //# of cities
    int arrayInt[v];  
    string in1, in2; 
    int in3;
    string arr[v] ;//cities 



    for(int i = 0 ; i < v ; i++)
    {
        string fill; 
        cin >> fill; 
        arr[i] = fill;  
    }
    for(int i = 0 ; i  < v ; i ++)
    {
        arrayInt[i] = i  ; 
    }
    


    // for(int print = 0 ; print < v ; print++)
    // {
    //     cout  << arr[print] << ":"; 
    // }
    // cout << endl; 

    cin >> e; //edges
    int twoD[v][e];
    for(int  i = 0 ; i < v; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            twoD[i][j] = -1;
            //cout << twoD[i][j] << " "; 
        }    
        //cout << endl; 
    }//sets equal -1
    

    
    for(int z = 0 ; z < e ; z++)
    {
        cin >> in1 >> in2 >> in3;

        //twoD[in1][in2] =  ;  
        //cout << "in1:" << in1 << "        in2:"<<in2 <<"    in3:" << in3 << endl; 
        int index1 = find(in1, arr, v);
        int index2 = find(in2, arr, v);
        //cout << " index1:"<< index1 << endl << " index2:" << index2 << endl; 
        if(index1 >= 0 && index2 >= 0)
        {
            twoD[index1][index2] = in3 ;
        }
    }
    


    //find_permutations(arrayInt , v, twoD);
    sort(arrayInt, arrayInt + v); 

	// Find all possible permutations 
	do 
	{ 
		 display(arrayInt, v);
         sum = 0 ; 
         for(int i = 0 ; i < v ; i++)
         {
             if(twoD[arrayInt[i]][i] >= 0 )
             {
                 sum+= twoD[arrayInt[i]][i];
             }
             else if(twoD[arrayInt[i]][i] == -1)
             {
                 break ; 
             }
             if(i == v-1 )
             {
                 //cout << " test 2" << sum<< endl;

                if(saveSum > sum)
                {
                    cout << " test" << endl ; 
                    saveSum = sum ; 
                }

             }
             //cout << "test 3" << endl; 
             
         } 

        
	} 
    while (next_permutation(arrayInt, arrayInt + v)); 
//print
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cout << twoD[i][j] << ' ';
        }
        cout  << endl;
    }
    
    /*
    cout << "Path:";
    for(int  i = 0 ; i < e; i++)
    {
        if(i < v)
        {
            cout << arr[i]; 
        }
        for(int j = 0 ; j < v ; j++)
        {
            
            if(twoD[i][j] >= 0 )
            {
                cout << "->" <<arr[j]; 
                sum += twoD[i][j]; 
            }
            //cout << twoD[i][j] << " "; 
        }    
        cout << endl; 
    }
    cout << "sum:" << sum << endl; 
    */




    // if(e == 0)//if only one city 
    // {
    //     for(int i = 0 ; i < v; i++)
    //     {
    //         cout << i << endl; 

    //     }
    // }
    cout << "SAVE SUM:" << saveSum << endl; 

    
}

int find(string inn , string arra[], int s)
{
    for(int p = 0 ; p < s ; p++)
    {
        if( inn == arra[p])
        {
            return p; 
        }      
    }
    return -1; 

}