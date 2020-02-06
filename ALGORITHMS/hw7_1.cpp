/*
 * HackerRank link:n/a
 * Title: hw7_1.cpp
 * Abstract: this program uses dytnamic memeory and finds max of given input 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 10/22/19
 * Version: 1.0 
 */

#include <iostream>
using namespace std;

void printArr(int *arr, int size)
{
    cout <<endl<<endl<< "::DEBUG FUNCTION PRINTING ARRAY::" << endl << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";  
    }
    cout << endl; 
}//end  print functiuon 


int sum_div_N_conq(int A[ ], int start, int end) 
{
    int max = -1;
    if(end == -1)
    {
        return -1; 
    } 
    if (start == end) {
        return start;
    }
    
    else {
        int sum1 = sum_div_N_conq (A, start, (start+end)/2);
        int sum2 = sum_div_N_conq (A, (start+end)/2+1, end);
        if(A[sum1] > A[sum2])
        {
            return sum1;  
        }
        if(A[sum2] > A[sum1])
        {
            return sum2; 
        }
        
    }
    return 0; 
}

int largest(int const num)
{
    int fill = num; 
    int * dynamA;
    int result = 0 ; 
    dynamA = new int [num]; //createdynamic array
    for(int i = 0 ; i < num ; i++)
    {
        cin >> dynamA[i] ; 
    }
    result = sum_div_N_conq(dynamA, 0, fill-1);
 
    return result ; 



}//end largest


int main() 
{
  int values; 
  cin  >> values; 
  //cout << "debug test # of values: " << values << endl; 
  int printMax = largest(values); 
  cout << "Max Index: " << printMax; 
  //cout <<endl<< "goodbye!" << endl; 
  return 0 ; 
}