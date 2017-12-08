#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class StockString {

public:
  string line;
  string line2;
  string line3;

};

int main()
{
  vector<StockString> list;
  StockString s;
 
  ifstream ifs {"stock.txt"};
  ifs >> s.line;
  ifs >> s.line2;
  ifs >> s.line3;
  cout << s.line << endl;
  cout << s.line2 << endl;
  cout << s.line3 << endl;
  return 0;  
}