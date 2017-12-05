#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>

// 10.4 of Stroustrup

using namespace std;

/** a structure with data fields for hour and temp */
struct Reading {
  int hour;
  double temp;
};

/** a list of readings */
vector<Reading> r;

int main()
{
  /** Prompt the user to get file names. Store them in a string and attach filestreams for reading and writing. Don't forget to verify that the files can be
    opened. */
  cout << "Please enter the input file: ";
  string iname;
  cin >> iname;
  cout << "Please enter the output file: ";
  string oname;
  cin >> oname;
  ifstream ist {iname};
  ofstream ost {oname};
  if(!ist || !ost)cout << "can't open file(s)"; //original code: error("can't open file",iname);

  /** Declare two variables to hold hour and temp readings */
  int hour;
  double temp;
  /** the input loop reads the numbers from the file and writes them in the output file */
  for(int i = 0; ist >> hour >> temp; i++ ) { 
    if (hour > 24 || hour < 0 ) {
      cout << "invalid time\n";
      return 1;
    }
    r.push_back(Reading{hour, temp});
  }

  /** the output loop writes the data from the Reading vector structs into the output file */
  for( int i = 0; i < r.size(); i++ )
    ost << "Hour: " << r[i].hour << " " << "Temperature: " << r[i].temp <<  " " << endl;
    
  cout << endl;
  return 0;


}