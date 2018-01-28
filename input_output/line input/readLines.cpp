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

int main()
{
  string command;
  getline(cin, command);
  //cout << command << endl;
  stringstream ss {command};
  vector<string> words;
  for(string s; ss >> s; )
    words.push_back(s);
  for ( vector<string>::iterator it = words.begin(); it != words.end(); ++it )
    cout << *it << endl;
  

  return 0;


}