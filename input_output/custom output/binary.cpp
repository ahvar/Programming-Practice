#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "errno.h"
#include <string>
#include <vector>


using namespace std;


int main()
{
  cout << "Please enter an output file name: ";	
  string oname;
  cin >> oname;
  ofstream ofs{oname, ios_base::binary};
  if(!ofs) {
  	cout << "can't open file\n";
  	return 1;
  }

  int x = 1;
  
  ofs.write( reinterpret_cast<char *>(&x), sizeof(int) * 1);
  ofs.close();

  cout << "Please enter input file name:\n";
  string iname;
  cin >> iname;
  ifstream ifs{iname, ios_base::binary};
  if(!ifs) {
  	cout << "can't open file\n";
  	return 1;
  }  
  
  int x1;
  ifs.read( reinterpret_cast<char *>(&x1), sizeof(int) * 1);
  cout << x1 << endl;
  ifs.close();
  
  return 0;

}