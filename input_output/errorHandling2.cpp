#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>

using namespace std;
// 10.6 of Stroustrup

void fillVector(istream &ist, vector<int> &v, char terminate)
{
  for(int i; ist >> i;) v.push_back(i);
  if(ist.eof()) { cout << "success" << endl; return; }
  ist.clear();
  char c;
  ist >> c;
  if (c!=terminate) {
    ist.unget();
    ist.clear(ios_base::failbit);
  }


}

int main()
{
  vector<int> vec;
  cout << "Enter several numbers separated by spaces: ";
  string s;
  isstream ist{s};
  fillVector(ist, vec, '\n'); 

  return 0;


}