#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>

// 10.4 of Stroustrup

using namespace std;
struct Reading {
  int hour;
  double temperature;
};

int main()
{
  cout << "Please enter the input file name: ";
  string iname;
  cin >> iname;
  cout << "Please enter the output file name: ";
  string oname;
  cin >> oname;
  ifstream ist {iname};
  ofstream ost {oname};
  if(!ist || !ost)cout << "can't open file(s)"; //original code: error("can't open file",iname);

  string contents;
  while(ist >> contents) {
    ost << contents << " ";
  }
  cout << endl;
  return 0;


}