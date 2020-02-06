/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/recursive-exponents/submissions/code/1316742897
   TITLE : hw5_1.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will find 2^n power where n is user input
      ID : 4444
    DATE : 10/4/19
  VERSION: 1.0

*/

#include <iostream> 
#include <iomanip>
using namespace std; 

//POWER FUNCTION REFERRENCED FROM URL:https://www.programiz.com/c-programming/examples/power-recursion
int power(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}
//END POWER FUNCTION REFERENCED FROM URL:https://www.programiz.com/c-programming/examples/power-recursion


int main()
{
    int input; 
    cin >> input; 
    int output = power(2, input);
    cout << output;
}