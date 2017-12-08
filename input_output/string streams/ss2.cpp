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
#include <typeinfo>
#include <error.h>
#include <err.h>

using namespace std;

template<typename Target, typename Source>

Target to(Source arg)
{
  stringstream interpreter;
  Target result;
  if(!(interpreter << arg) || !(interpreter >> result) || !(interpreter >> ws).eof())
    throw runtime_error{"to<>() failed"};
  return result;
}

template<typename T> string to_string(const T &t)
{
  ostringstream os;
  os << t;
  return  os.str();

}

struct badFromString : bad_cast {


  const char* what() 
  {
    return "bad cast from string";
  }

};

template<typename T> T fromString(const string &s)
{
  istringstream is{s};
  T t;
  if(!(s>>t))throw badFromString{};
  return t;

}
  


int main()
{
  string s1 = to_string(12.333);
  string s2 = to_string(45);
  cout << s1 << '\n' << s2 << endl;
  
  double d = fromString<double>("12.333");
  cout << d << endl;

  int dd = fromString<int>("Mary had a little lamb");
  string s = "this is a string";
  try {
    int i = fromString<int>(s);
    cout << i << endl;
  }catch(badFromString e) {
    error("bad input string", s);
  }
  
  return 0;
}