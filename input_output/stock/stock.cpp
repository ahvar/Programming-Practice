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
  vector<StockString *> list;
  StockString s;
  StockString &sptr = s;
  ifstream ifs {"stock.txt"};
  ifs >> sptr.line;
  ifs >> sptr.line2;
  ifs >> sptr.line3;
  cout << sptr.line << endl;
  cout << sptr.line2 << endl;
  cout << sptr.line3 << endl;
  cout << s.line << endl;
  cout << s.line2 << endl;
  cout << s.line3 << endl;
  return 0;  
}