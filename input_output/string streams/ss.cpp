#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <cstdio>
#include <ostream>
#include <cmath>
#include <stdexcept>

using namespace std;

struct Temperature {
  double temp;
  string unit;
};

double str_to_double( string s )
{
  istringstream is {s};
  double d;
  is >> d;
  if (!is)
    cout << "double format error:" << endl;
  return d;

}

void my_code(string label, Temperature temp )
{
  ostringstream os;
  // compose the os string
  // a gui object calls a display function and calls os.str() function
  // see 11.4 in C++ book for example


}
int main()
{
  double d1 = str_to_double("12.3");
  double d2 = str_to_double("18.2");
  double d3 = str_to_double("one point eight"); //error
  
  ostringstream os;
  string first = "first";
  string last = "last";
  os << "Name: " << first << " " << last << endl;
  cout << os.str() << endl;

  Temperature t;
  t.temp = 34.1;
  t.unit = "Celcius";
  

  return 0;


}