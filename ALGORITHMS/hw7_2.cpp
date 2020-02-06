/*
 * HackerRank link:
 * Title: hw7_2.cpp
 * Abstract: 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 10/22/19
 * Version: 1.0 
 */

#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include <time.h>
#include <bits/stdc++.h>
#include <math.h>
#include <random> 
#include <array>
using namespace std; 
using namespace std::chrono;

//begins with referenced arrays, MAIN at bottom
//BEGIN MERGE SORT REFERENCED FROM URL:https://www.geeksforgeeks.org/merge-sort/
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

//END MERGE SORT REFERENCED CODE

//BEGIN QUICK SORT REFERENCED FROM URL: https://www.geeksforgeeks.org/quick-sort/

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
//freferenced code from http://www.cplusplus.com/reference/ctime/clock/
int frequency_of_primes (int n) {
  int i,j;
  int freq=n-1;
  for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;
}
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
//END REFERENCED CODE QUICK SORT 

//BEGIN REFERENCED CODE INSERTION SORT URL: https://www.geeksforgeeks.org/insertion-sort/

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
//end referenced code insertion sort 
//END ALL REFERENCED CODE::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int * timeMe(int num)
{
    int * dynamA; 
    dynamA = new int [num]; //createdynamic array
    for(int i = 0 ; i < num ; i++)//fill dynamic array 
    {
        //cin >> dynamA[i] ; 
        dynamA[i] = i; 
        //cout << "DEBUG: entered #[" << i << "into  " << dynamA[i] << "] into dynamic array" << endl; 
    }
    return dynamA; 
}//end timeME
//start timer
int timer(const int num, int arr[])//determine time complexity
{
    clock_t t1, t2, t3; 
    int f1, f2, f3 ; 
    int * fillArray; 

    //timer for insertion sort
    fillArray = arr; //set fill as arr initial values
    auto start = high_resolution_clock::now(); 
    t1 = clock(); //start clock 1
    // Call the function to be timed 
    insertionSort(fillArray, num);
    f1 = frequency_of_primes (99999);; 
    t1 = clock() - t1;//end clock 1
    printf ("Insertion sort: %f seconds.\n",t1,((float)t1)/CLOCKS_PER_SEC);

    //timer for merge sort 
    fillArray = arr; //set fill as arr initial values
    auto startM = high_resolution_clock::now(); 
    t2 = clock(); //start clock 2
    // Call the function to be timed 
    mergeSort(fillArray, 0, num); 
    f2 = frequency_of_primes (99999);
    t2 = clock() - t2;//stop clock 2
    printf ("Merge sort:     %f seconds.\n",t2,((float)t2)/CLOCKS_PER_SEC);

    //timer for quick sort
    fillArray = arr; //set fill as arr initial values
    t3 = clock(); 
    quickSort(fillArray, 0, num);
    f3 = frequency_of_primes (99999); 
    t3 = clock() - t3;
    printf ("Qucik sort:     %f seconds.\n",t3,((float)t3)/CLOCKS_PER_SEC);

    return 0 ; 
}
//end timer function
int * order(int size)//function to order the results ?
{
    
    //cout << "debug: order function hit::" << endl;\
    //int * arra; arra = timeMe(size);
    int order = 0;
    cout << "========== Select Order of Input Numbers ==========" << endl 
       << "1.  Ascending Order"  << endl
       << "2. Descending Order" << endl
       << "3.     Random Order"     << endl
       << "Choose Order:" ; 
    cin>>order; 
    //int * arra; arra = timeMe(size); 
    //   cout << "debug printing array:" ; 
    //   printArray(arra, inputSize); 
    //   cout << endl; 
    cout << "============================================================"<< endl;
    //order function goes here
    
    int * fill; fill = timeMe(size);
    
    if(order == 1 )
    {
        //ascending 
        cout << "Generate input data in ascending order . . ." << endl; 
        //printArray(fill, size); //debug test array
        cout << "Done." << endl;
        cout << "============================================================"<< endl;
        cout << endl << endl;  //gap

        cout << "============================================================"<< endl;
        timer(size, fill); 
        cout << "============================================================"<< endl;  
        

    }
    if(order == 2 )
    {
        //decending 
        cout << "Generate input data in decending order . . ." << endl; 
        reverse(fill, fill+size); //descending order 
        //printArray(fill, size); //debug test array
        cout << "Done." << endl;
        cout << "============================================================"<< endl;
        cout << endl << endl;  //gap

        cout << "============================================================"<< endl;
        timer(size, fill); 
        cout << "============================================================"<< endl;
         

    }
    if(order == 3 )
    {
        //random 
        cout << "Generate input data in random order . . ." << endl; 
        random_shuffle(fill, fill+size); 
        //printArray(fill, size); //debug test array
        cout << "Done." << endl; 
        cout << "============================================================"<< endl;
        cout << endl << endl;  //gap

        cout << "============================================================"<< endl;
        timer(size, fill); 
        cout << "============================================================"<< endl;
        
    }
    
    return fill; 
}



int main() {
  //std::cout << "Hello World!\n";
  int inputSize; 
  cout << "Please enter input size:" ; 
  cin>>inputSize ; 
  order(inputSize);

}