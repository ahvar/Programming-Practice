#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>

using namespace std;
// 10.7 of Stroustrup

struct Date {
  int month;
  int day;
  int year;
};

struct Time {
  int hour;
  int minute;
  int sec;
};

ostream &operator<<( ostream &os, Date &d)
{
  os << "Month: " <<  d.month << "Day: " <<
    d.day << "Year: " << d.year;
  return os; 

}

ostream &operator<<( ostream &os, Time &t)
{
  os << "Hour: " << t.hour <<
    "Minute: " << t.minute << "Second: " << t.sec;
  return os;


}

istream &operator>>( istream &is, Date &d )
{
  int y, m, d;
  if(d.month && d.day && d.year) is >> d.month >> d.day >> d.year;
  return is;

}

int main()
{
  Date date;
  date.month = 12;
  date.day = 5;
  date.year = 2017;

  Time time;
  time.hour = 24;
  time.minute = 13;
  time.sec = 45;

  cout << date << endl;
  cout << time << endl;
  return 0;


}