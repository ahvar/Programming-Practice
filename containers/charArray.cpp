#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


class CName {
public:
  enum {
    sizeOfBuffer = 256
  };
  
  char m_szFirst[sizeOfBuffer];
  char m_szLast[sizeOfBuffer];

public:
  void setName( char *pszFirst, char *pszLast )
  {
    strcpy_s( m_szFirst, sizeOfBuffer, pszFirst );
    strcpy_s( m_szLast, sizeOfBuffer, pszLast );
  }
};

int main(void) {
  char *pCharArray = new char[CName::sizeOfBuffer];
  strcpy_s(pCharArray, CName::sizeOfBuffer, "Array of characters");

  delete [] pCharArray;
  pCharArray = NULL;

  CName *pName = new CName;
  pName->setName("Firstname", "Lastname");
  return 0;
}