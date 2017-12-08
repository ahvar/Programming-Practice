#include "location_v2.h"

using namespace std;


int main()
{
  
  string a1; 
  string a2; 
  string ctyAndSt;
  string zp; 
  string env;

  /** cin will terminate when it hits whitespace */
  cout << "Enter the street address line: ";
  getline( cin, a1 ); 
  cout << "If there is one, enter the suite, building, or apt #: ";
  getline( cin, a2 );
  cout << "Enter the city and state: ";
  getline( cin, ctyAndSt );
  cout << "Enter a zip code: ";
  getline( cin, zp );
  cout << "Is this address in a rural or urban environment: ";
  getline( cin, env );

  cout << "The location is at: \n" << a1 + '\n' << a2 + '\n' << ctyAndSt + " " + '\n' << env + '\n';

  size_t comma = ctyAndSt.find(",");
  string cty = ctyAndSt.substr( 0, comma );
  string st = ctyAndSt.substr( comma + 2, ctyAndSt.length() );

  Location l( a1, a2, cty, st, zp, env );

  cout << l << endl;

  return 0;

}