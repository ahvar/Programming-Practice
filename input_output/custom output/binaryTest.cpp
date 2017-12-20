/** the original code for the below example comes from: <script src="https://gist.github.com/molpopgen/9123133.js"></script> */

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
  string str("Test string");
  unsigned Y = 11;
  vector<double> Z(10, 1.0);

  cout << "Please enter an output file name: "; 
  string oname;
  cin >> oname;
  ofstream ofs{oname, ios_base::binary};
  if(!ofs) {
    cout << "can't open file\n";
    return 1;
  }
  // to write a string print out its length and then char *
  // str.size() is a temp, and you cannot write a temp, so you need a new variable
  unsigned strSize = str.size();
  ofs.write(reinterpret_cast<char *>(&strSize), sizeof(unsigned));

  strSize = Z.size();
  ofs.write( reinterpret_cast<char *>(&strSize), sizeof(unsigned));
  ofs.write( reinterpret_cast<char *>(&Z[0]), Z.size()*sizeof(double));
  ofs.close();

  cout << "Please enter input file name:\n";
  string iname;
  cin >> iname;
  ifstream ifs{iname, ios_base::binary};
  if(!ifs) {
  	cout << "can't open file\n";
  	return 1;
  }  
  // declare a variable of unsigned type to hold the memory for storing binary data
  unsigned strSize2;
  // cast the memory address of this storage location as a char pointer and pass it to the first parameter of the read method
  // called on input filestream. the second parameter is the size of a single unsigned variable
  ifs.read( reinterpret_cast<char *>(&strSize2), sizeof(unsigned));

  // create a char array of the same size as the unsigned variable
  // setup an input filestream pointing to the first character in the temp array and set its size to that of the strSize 
  // specified previously
  vector<char> temp(strSize2);
  ifs.read( reinterpret_cast<char *>(&temp[0]), strSize2 * sizeof(char));
  string theString( temp.begin(), temp.end());
  
  unsigned vsize;
  ifs.read( reinterpret_cast<char *>(&vsize), sizeof(unsigned));
  vector<double> thedoubles(vsize);
  ifs.read (reinterpret_cast<char *>(&thedoubles[0]), vsize*sizeof(double));

  cout << strSize2 << ' ' << theString << '\n' << vsize << ' ';
  for(unsigned i = 0; i < thedoubles.size(); ++i ) {
    cout << thedoubles[i] << ' ';
  }
  cout << '\n';

  ifs.close();
  return 0;

}