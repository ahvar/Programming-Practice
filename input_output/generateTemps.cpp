#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>
#define MNSTART 1
#define MNSTOP 12
#define YEARS 3
#define HOURS 23
#define DAYS 30

using namespace std;
// 10.7 of Stroustrup


double getRandomTemp()
{
  double r = rand() % 10 + 50; 
  return r;
}



int main()
{
  ofstream ost{"datesAndTemps.txt"};
  
  for( int yr = 1989; yr < 1990; yr++ ) {
    ost << "{year" << yr;

    for (int mn = MNSTART; mn < MNSTOP; mn++ ) {
      ost << "{month" << mn;

      for ( int d = 1; d < DAYS; d++ ) {
        ost << "{day" << d;
        for( int hr = 0; hr <= HOURS; hr++ )
          ost << "{ " << hr << " " << getRandomTemp() << " }";
        ost << "}";

      }
      ost << "}";
    }
    ost << "}";
  }
     
  return 0;

}