/** 10.7 of Stroustrup */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>
#define MNSTART 1
#define MNSTOP 3
#define YEARS 3
#define HOURS 2
#define DAYS 5

using namespace std;

const int notAMonth = -1;
const int notAReading = -7777;

/**
  The Reading struct contains the temperature for a particular date
*/
struct Reading {
  /** The hour on a 24-hr clock */
  int hour;
  /** The day in a month */
  int day;
  /** The month in a calendar year */
  int month;
  /** A between 1900 and 2100 */
  int year;
  /** The temperature at hour x, day n, month m, year y */
  double temp;

  /**
    Constructor for Reading.
    @param hr the hour
    @param dy the day
    @param mn the month
    @param yr the year
    @param tmp the temperature
  */
  Reading( int hr, int dy, int mn, int yr, double tmp ) : hour(hr), day(dy), month(mn), year(yr), temp(tmp){}

  /**
    The default constructor for Reading
  */
  Reading(){}

};

/**
  Returns a randomly generating double between 50 and 60 to be read as the temperature.
  Called by the generateData() function.

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

/**
  Checks that the stream state is not bad() or fail() and that the next character in the stream is '{'.
  If the next character is not '{' we put the unexpected character back into the stream for return to the caller, 
  clear the stream, and set to fail(). 

  @param is the file stream
  @return the file stream
*/
ifstream &goodBeginning( ifstream &is )
{
  char ch1;
  if( is >> ch1 && ch1 != '{' )  {
    cout << "data format error" << endl;
    return putBackAndFail(is);
  }
  return is;
}

/**
  Checks that the stream state is not bad() or fail() and that the next character in the stream is '}'.
  If the next character is not '}' we put the unexpected character back into the stream for return to the caller, 
  clear the stream, and set to fail(). 

  @param is the file stream
  @return the file stream
*/
ifstream &goodEnding( ifstream &is ) {
  char ch1;
  if( is >> ch1 && ch1 != '}' )  {
    cout << "data format error" << endl;
    return putBackAndFail(is);
  } 
  return is;

}

/**
  Reads alpha characters preceeding the digit indicating year, month, or day.
  @param is a reference to the input filestream
  @return true if stream state is not bad() or fail()
*/
ifstream &readLetters( ifstream &is ) {
  char letter;
  while( !isdigit(letter) ) 
    is >> letter;
  if( !is ) {
    return putBackAndFail(is);
  }
  is.unget();
  return is;
}

/**
  Puts the most recently read character back in the filestream so it can be returned to the caller.
  @param is reference to input filestream
  @return reference to input filestream
*/
ifstream &putBackAndFail( ifstream &is ){
  is.unget();
  is.clear(ios_base::failbit);
  return is;
}
 
ifstream &readHoursAndTemps( ifstream &is, Reading &r ) {
  while(goodBeginning(is)){
    is >> r.hour >> r.temp;
    if(goodEnding(is))
  }
}
/**
  Overloaded right-shift operator for inputting temperature readings from file.

  @param is reference to filestream
  @param r Reading struct
  @return is filestream
*/
ifstream &operator>>( ifstream &is, Reading &r )
{
  int unit = 0;
  while( goodBeginning(is) && unit < 3) {
    getLetters(is);
    if ( unit == 0 )
      is >> r.year;
    else if ( unit == 1 )
      is >> r.month;
    else if ( unit == 2 )
      is >> r.day;
    else if ( unit == 3 )
      readHoursAndTemps(is, r);
    unit++;
  }
  is >> r.temp;

    


  return is;

}

int main()
{
  //ofstream ost{"datesAndTemps2.txt"};
  ofstream ost{"datesAndTemps2.txt"};
  
  generateData( ost );
  
  ost.close();

  Reading r{};
  vector<Reading> temps;
  temps.push_back(r); 
  
  ifstream ist{"datesAndTemps2.txt"};

  for (int i = 0; ist >> temps[i]; i++ ) {
    ist >> temps[i];
  } 

  ist.close();
  
  return 0;

}