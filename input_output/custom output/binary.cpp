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

  vector<int> x(10);
  for ( int i = 0; i < 10; i++ )
  	x.push_back(i);
  unsigned xSize = x.size();
  ofs.write( reinterpret_cast<char *>(&xSize), sizeof(unsigned));
  for (int i = 0; i < (int) x.size(); i++)
  	ofs.write( reinterpret_cast<char *>(&x[i]));
  ofs.close();

  cout << "Please enter input file name:\n";
  string iname;
  cin >> iname;
  ifstream ifs{iname, ios_base::binary};
  if(!ifs) {
  	cout << "can't open file\n";
  	return 1;
  }  
  
  vector<int> x1(10);
  xSize = x1.size();
  ifs.read( reinterpret_cast<char *>(&xSize), sizeof(unsigned));
  for ( int i = 0; i < (int) x1.size(); i++ )
  	ifs.read( reinterpret_cast<char *>(&x1[0]), size);
  for(int i = 0; i < (int) x1.size(); i++)
  	cout << x1[i] << endl;
  ifs.close();
  
  return 0;

}