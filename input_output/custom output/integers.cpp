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
  int a, b, c, d;
  cin >> a >> hex >> b >> oct >> c >> d;
  cout << a << "\t" << b << '\t' << c << '\t' << d << '\n';

  cout << 1234 << "\t(decimal)\n" << hex << 1234 << "\t(hexadecimal)\n" << oct << 1234 << "\t(octal)\n";
 
  int e, f, g, h;

  /** The stream member function unsetf() clears the flag (or flags) given as argument.*/
  cin.unsetf(ios::dec);
  cin.unsetf(ios::hex);
  cin.unsetf(ios::oct);
  cin >> e >> f >> g >> h;
  cout << e << "\t(decimal)" << f << "\t(octal)" << g << "\t(hexadecimal" << h;

  cout << 1234.5678 << "\t\t(defaultfloat)\n" << fixed << 1234.56789 << "\t(fixed)\n" << scientific << 1234.56789 << 
    "\t(scientific)";

  cout << 123456 << '' << setw(4) << 123456 << '' << setw(8) << 123456 << '\n';
  return 0;


}