#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>

using namespace std;

struct Reading{
  double reading;
  Reading(double r) : reading(r){}
};

int main()
{
  // declaring a vector of doubles
  vector<double> hour1[25];
  // another way of declaring vector
  vector<double> hour{vector<double>(24, -77)};
  //cout << hour1.size() << endl; // this won't work b/c hour1 has not been instantiated
  
  vector<Reading *> list;
  ifstream ist{"doubles.txt"}; 
  for( int i = 0; ist >> hour[i]; i++) {
  	Reading *rr = new Reading(hour[i]);
    list.push_back(rr);
  }

  // this loop accesses the Reading vector with a messing and confusing notation
  for( int i = 0; i < (int) list.size(); i++)
  	cout << (*list[i]).reading << endl;
  
  cout << "print the data again" << endl;
  
  // this loop accesses the Reading vector named list with a '->' notation for accessing a structure's data pointed 
  // to by some variable
  for( int i = 0; list[i] ; i++ )
  	cout << list.at(i)->reading << endl;



  return 0;

}