/** 10.7 of Stroustrup */
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

const int notAMonth = -1;
const int notAReading = -7777;

/**
  A Day has 24 hours each initialized to notAReading (-7777)
*/
struct Day {
  int day;
  //constructs vector with 24 elements with each element a copy of notAReading
  //we want to specify the number of elements for a vector for which an integer can be converted to the element type. to do this we 
  // use the below syntax instead of vector<double> hour(24, notAReading);
  vector<double> hour {vector<double>(24,notAReading)};

};

struct Month {
  int month{notAMonth};
  vector<Day> day{32};
};

struct Year {
  int year;
  vector<Month> month{12};
};

/**
  The Reading struct contains the temperature for a particular date
*/
struct Reading {
  Year year;
  Month month;
  Day day;

  double temp;

};

/**
  Returns a randomly generating double between 50 and 60 to be read as the temperature.
  @return r the randomly generated temperature
*/
double getRandomTemp()
{
  double r = rand() % 10 + 50; 
  return r;
}


/**
  Outputs dates and temperatures in a format intended to simulate how raw data may be encountered in the world. 
  The format is:

  {year1989{month1{day1{ 0 53 }{ 1 56 }{ 2 57 }....}}

  @param ost the output stream
*/
void generateData( ostream &ost )
{

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

}

void readData()
{




}

istream &operator>>( istream &is, Year &yr )
{
  char ch1;
  while( !isdigit(ch1) )
    is >> ch1;
  is.unget();
  is >> yr.year;
  return is;

}

istream &operator>>( istream &is, Month &mn )
{
  char ch1;
  while( !isdigit(ch1) )
    is >> ch1;
  is >> mn.month;
  

  return is;

}

istream &operator>>( istream &is, Day &dy )
{
  char ch1;
  while( !isdigit(ch1) )
    is >> ch1;
  is.unget();
  is >> dy.day;
  for(int i = 0; i < 24; i++) {
    if(is>>ch1 && ch1 != '{') {
      is.unget();
      is.clear(ios_base::failbit);
      return is;
    } 
    int hr;
    is >> hr >> dy.hour[i];
    if(is>>ch1 && ch1!= '}') {
      is.unget();
      is.clear(ios_base::failbit);
      return is;
    }
  }
  
  return is;

}

/**
  Checks that the stream state is not bad() or fail() and that the next character in the stream is '{'.
  If the next character is not '{' we put the unexpected character back into the stream for return to the caller, 
  clear the stream, and set to fail(). 

  @param is the file stream
  @return the file stream
*/
bool verifyStream( istream &is )
{
  char ch1;
  is >> ch1;
  if( ch1 != '{' || !is )  {
    is.unget();
    is.clear(ios_base::failbit);
    return false;
  }
  return true;
}

ifstream &operator>>( ifstream &is, Reading &r )
{
  char ch1;

  if ( !verifyStream(is) ) {
    cout << "problem reading file";
    return is;
  }
  is >> r.year >> r.month >> r.month.day;
  for (int i = 0; i < r.month.day.hour.size(); i++) {
    r.temp = r.month.day.hour[i];
  }
  //while(r.month.day) {
    //r.temp = r.month.day.hour;
    //r.month.day.hour++;
  //}
  return is;

}

void getTemps(ifstream &is)
{
  if( !is ) {
    cout << "problem reading file" << endl;
    return is;
  }
  readYear(is);
  readMonth(is);
  char ch1;
  if( is >> ch1 && ch1 != '{' )


}

int main()
{
  ofstream ost{"datesAndTemps.txt"};
  
  generateData( &ost );

  

  ost.close();

  ifstream ist {"datesAndTemps.txt"};

  Reading tmps;
  ist >> tmps;
    
    
     
  return 0;

}