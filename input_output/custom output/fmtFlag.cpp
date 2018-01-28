#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  ios_base::fmtflags original_flags = cout.flags();
  cout << "Original flag value: " << original_flags << '\n';
  cout << 812 << '\n';
  cout << "Left align and specify a 10 character field width." << '\n';
  cout.setf(ios_base::left, ios_base::adjustfield);
  cout.width(10);
  cout << 813 << 815 << '\n';
  // reset all format flags
  cout.unsetf(ios_base::adjustfield);
  streamsize original_precision = cout.precision(2);
  cout << "Original precision value: " << original_precision << '\n';
  cout << 831.0 << ' ' << 8e2;

  // The field width automatically resets to its default value 0 after each input or output
  // operation that uses the field width. As extraction of integers does not use the field
  // width setting, the field width of 10 is still in effect after evaluation of the subexpression
  // cin >> i.
  int i; string s;
  cin.width(10);
  cin >> i >> s;
  
  
  return 0;
}