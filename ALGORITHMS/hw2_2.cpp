/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/time-difference-2/submissions/code/1316175586
   TITLE : hw2_2.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will display the difference between two different time stamps 
      ID : 4444
    DATE : 9/6/19
  VERSION: 1.0

*/
#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std; 


struct timeStamps 
{
  int hour, 
      min, 
      sec; 
  timeStamps(){hour= 0 ;min=0;sec=0;}; //constructor

} ; 

ostream& operator<<(ostream& os, const timeStamps& t) {
    os << setw(2) << setfill( '0' )<< t.hour << ":" << setw(2) << setfill( '0' )<< t.min << ":" << setw(2) << setfill( '0' )<< t.sec << endl;
    return os;
}



//prototypes:
void timeDiff(timeStamps &t1,timeStamps &t2);
void display(); 

int main() 
{
  timeStamps time1, time2; 
  int hour, min, sec; 
  char fill; 

  //store first timeStamp
  cin >> hour >> fill >> min >> fill >> sec ;
  if(hour < 23 && min < 60 && sec < 60)
  {
    time1.hour = hour; 
    time1.min = min; 
    time1.sec = sec;
  } 

  cin >> hour >> fill >> min >> fill >> sec ;
  if(hour < 23 && min < 60 && sec < 60)
  {
    time2.hour = hour; 
    time2.min = min; 
    time2.sec = sec;
  }
  timeDiff(time1, time2);
}//end main


//function definitions
void timeDiff(timeStamps &t1 ,timeStamps &t2)
{
    if(t2.hour == t1.hour && t2.min == t1.min && t2.sec == t2.sec)//if timestamps are identical 
    {
        cout << t1;
        return ;  
    }
    if(t2.hour < t1.hour )
    {
        t2.hour += 24;  
    }
    t2.hour -= t1.hour;
    t2.min -= t1.min;
    t2.sec -= t1.sec;

    //fix negatives if any
    if(t2.sec < 0)
    {
        t2.sec += 60; 
        t2.min -= 1 ; 
    }
    if(t2.min < 0)
    {
        t2.min += 60; 
        t2.sec -= 1 ; 
    }
    cout << t2; 
}//end timeDiff
