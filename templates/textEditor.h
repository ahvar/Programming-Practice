#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>


template<class Line>
std::vector<char>;


struct Document{
  std::list<Line> line;
  Document() { line.push_back(Line{}); }

};

std::istream &operator>>(std::istream &is, Document &d)
{
  for(char ch; is.get(ch);) {
    d.line.back().push_back(ch);
    if(ch=='\n')
      d.line.push_back(Line{});
  }
  if(d.line.back().size()) d.line.push_back(Line{});
  return is;

}

class TextIterator {
  list<Line>::iterator ln;



};