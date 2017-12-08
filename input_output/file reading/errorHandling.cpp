#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>

// 10.6 of Stroustrup


int main()
{
  cout << "Enter a number: " << endl;
  int a;
  cin >> a;
  while(cin) {
    cout << "Enter another number: " << endl;
    cin >> a;
  }
  if(cin.bad()) cout << "stream corrupt" << endl;
  if(cin.eof()) cout << "end of file" << endl;
  if(cin.fail()) { cout << "something unexpected happened" << end; cin.clear(); cout << "recovered" << endl; }0
  return 0;


}