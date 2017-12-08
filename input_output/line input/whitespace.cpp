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

class PunctStream {
public:
  PunctStream(istream &is) : source{is}, sensitive{true} {}
  void whitespace(const string &s) { white = s; }
  void addWhite(char c) { white += c; }
  bool isWhitespace(char c);
  void caseSensitive(bool b) { sensitive = b; }
  bool isCaseSensitive() { return sensitive; }

  PunctStream &operator>>(string &s) {
    while(!(buffer>>s)) {
      if(buffer.bad() || !source.good()) return *this;
      buffer.clear;
    
      string line;
      getline(source, line);
      char &ch;
      for( int i = 0; i < (int)line.size(); i++ ) {
        *ch = line[i];
        if(isWhitespace(*ch) *ch = ' ';
        else if( !sensitive ) *ch = tolower(ch);
      }
      buffer.str(line);
    }
    return *this;
  operator bool();
private:
  istream &source;
  istringstream buffer;
  string white;
  bool sensitive;

};

int main()
{
  PunctStream ps{cin};
  ps.whitespace(";,:");
  ps.caseSensitive(false);
   

  return 0;


}