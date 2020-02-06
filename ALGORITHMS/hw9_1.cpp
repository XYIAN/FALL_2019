    /*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw9/challenges/max-heap-1-2/submissions/code/1317688854
 * Title: hw9_1.cpp
 * Abstract: This program will construct and preform operations on a heap with user input ; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 11/13/19
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


//REFERENCED FROM https://www.tutorialspoint.com/cplusplus-program-to-implement-max-heap
void max_heap(vector<int> a, int m, int n) {
   int j, t;
   t = a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] > a[j])
         j = j + 1;
      if (t > a[j])
         break;
      else if (t <= a[j]) {
         a[j / 2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = t;
   return;
}

void build_maxheap(vector<int> a,int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      max_heap(a,k,n);
   }
}

//REFERENCED FROM https://www.geeksforgeeks.org/heap-sort/
void heapify(vector<int> a, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i; // left = 2*i
    int r = 2*i + 1; // right = 2*i + 1
    // cout << "largest:  " << arr[largest] << " left: " << arr[l] << " right: " << arr[r] << " size: " << n << endl;
  
    // If left child is larger than root 
    if (l <= n && a[l] > a[largest])
        largest = l;
  
    // If right child is larger than largest so far 
    if (r <= n && a[r] > a[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(a, n, largest); 
    } 
    else
    {
        heapify(a, n, largest/2); 
    }
} 
//END REFERENCED CODE ======

void display(int size1, vector<int> a)
{
    for(int i = 1 ; i < size1+1; i++)
    {
        cout << a.at(i) << " " ; 
    }
    cout << endl; 

}//end display 

void insert(int n1, vector<int> a, int size)
{ 
    cout << "test"; 
    a.push_back(n1);
    
}//end insert 


void displayMax(vector<int> a)
{
    
    cout << a[1] << endl; 
    // return true;
}//end displayMax

vector<int> deleteMax(int size2, vector<int> a)
{
    a.erase(a.begin());
    return a; 
}//end delete max 

int deleteMe(int num, int size, vector<int> a)
{
    int * f3; f3 = new int [size];
    int toReturn;
    for(int i = 1 ; i < size; i ++)
    {
        if(a.at(i) == num)
        {
            a[i] = a[size];
            toReturn = i;
            size--; 
        }
    }

    return toReturn;
}//end deleteMe

bool isHeap(vector<int> a, int root, int size)
{
    if(root > size/2)
    {
        return true;
    }
    int l = 2*root;
    int r = 2*root+1;

    if(a[root] >= a[l] && a[root] >= a[r] && isHeap(a, l, size) && isHeap(a, r, size))
    {
        return true;
    }

    return false;
}

void read()
{
    int size, 
        operationNum ,
        fill; 
    cin >> size; 
    int sz = size; 
    vector<int> a(size); //size the array
    // cout << "debug size:" << size << endl; 
    for(int i = 1 ; i < size+1 ; i++)
    {
        cin >> fill; 
        a.push_back(fill); 
        // cout << "array at["<<i<<"] is: "<< a[i]<< endl;

    }

    cin >> operationNum; 
    if(!isHeap(a, 1, size))
    {
        cout << "This is NOT a heap." << endl;
        build_maxheap(a, size); 
    }
    else
    {
        cout << "This is a heap." << endl;
    }
    string test; 
    getline(cin, test);
    
 
    
    
    for(int i = 0 ; i < operationNum ; i++)
    {
        
        string input;
        cin >> input;
        if(input == "insert")
        {
            int f1; cin >> f1; 
            size++;
            insert(f1, a, size);
            heapify(a, size, size/2);
        }
        else if(input =="displayMax")
        {
            displayMax(a);
        } 
        else if(input =="deleteMax")
        {
            deleteMax(size, a);
            size--;
            heapify(a, size, 1);
        }
        else if(input =="delete")
        {
            int f2; cin >> f2; 
            int spot = deleteMe(f2, size, a); 
            size--;
            heapify(a, size, spot);
        }
        else if(input =="display")
        {
            display(size, a);
        }
    }



}


//START MAIN 
int main() 
{
    // cout << " debug program start..." << endl;
    // int * arr; 
    read();  
}
//END MAIN 

/*
======NOTES=======
-index 1 reserved for root 
-index*2 = left child 
-(2*index)+1 = right child
-
======INPUT=======
//not heapifying all the way up the heap.
6
20 15 10 5 1 2
5
insert 30
deleteMax
display
delete 15
display

//not heapifying all the way up the heap
11
99 55 88 44 33 66 77 22 11 5 3
6
insert 2
delete 55
display
insert 50
delete 33
display

19
100 99 98 97 96 95 94 93 92 91 80 70 60 50 40 71 72 73 74 
6
displayMax
insert 1
delete 40
display
delete 98
display

======OUTPUT======


*/