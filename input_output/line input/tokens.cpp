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
#include <vector>

using namespace std;

/** the istream::get() function reads a single character and does not skip whitespace. get() returns a reference to its istream so that we can test its state. */

/*************************************** STANDARD LIBRARY FUNCTIONS FOR CHARACTER CLASSIFICATION ****************************************************************


isspace(c) -- isalpha(c) -- isdigit(c) -- isxdigit(c) -- isupper(c) -- islower(c) -- isalnum(c) -- iscntrl(c) -- ispunct(c) -- isprint(c) -- isgraph(c)


****************************************************************************************************************************************************************/
string &makePunctWhitespace(string &line)
{
  //getline(cin, line);
  char ch;
  for(int i = 0; i < (int)line.size(); i++ ) {
    ch = line[i];
    switch(ch){
      case ';' : case ',' : case '?' : case '!' : ch = '';
    }
  }
  stringstream ss(line);
  vector<string> vs;
  for( string word; ss>>word; )
    vs.push_back(word);
  return ss.str(line);

}

void tolower(string &s)
{
  for (char &x : s)x = tolower(x);

}
int main()
{
  for( char ch; cin.get(ch); ) {
    if(isspace(ch)) { //do nothing }
    if(isdigit(ch)) { }
    else if(isalpha(ch)){}
    else{}
  }
  

  return 0;


}