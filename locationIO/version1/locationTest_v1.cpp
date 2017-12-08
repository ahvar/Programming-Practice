#include "location_v1.h"

using namespace std;

void allocateMemory( char *add, char *add2, char *cAndS, char *z, char *e )
{
  add = (char *)malloc( sizeof(char) * 40 );
  add2 = (char *)malloc( sizeof(char) * 40 );
  cAndS = (char *)malloc( sizeof(char) * 40 );
  z = (char *)malloc( sizeof(char) * 40 );
  e = (char *)malloc( sizeof(char) * 40 );    

}
int main()
{
  
  //string a1; 
  //string a2; 
  //string ctyAndSt;
  //string zp; 
  //string env;
  char a1;
  char a2;
  char ctyAndSt;
  char zp;
  char env;

  allocateMemory( &a1, &a2, &ctyAndSt, &zp, &env );

  /** cin will terminate when it hits whitespace */
  cout << "Enter the street address line: ";
  gets( &a1 );
  cout << &a1 << endl;
  cout << "If there is one, enter the suite, building, or apt #: ";
  gets( &a2 );
  cout << &a2 << endl;
  cout << "Enter the city and state: ";
  gets( &ctyAndSt );
  cout << &ctyAndSt << endl;
  cout << "Enter the zip code: ";
  gets( &zp );
  cout << &zp << endl;
  cout << "Is this address in a rural or urban environment: ";
  gets( &env );
  cout << &env << endl;
  
  //char *cty = strtok( &ctyAndSt, ",");
  //char *st = strtok( &ctyAndSt, " " );

  printf("%s\n%s", &a1, &a2);
  //<< &a2 << endl << &cty << endl << &st << endl << &zp << endl << &env;

  /** overload the constructor to accept string parameters or char pointer parameters */
  //Location l(&a1, &a2, cty, st, &zp, &env);
  return 0;

}