#include "kennel.h"

std::ostream &operator<<( std::ostream &out, Kennel &k )
{
  Dog *dg = k.kennel.front();
  while ( dg ) {
    out << *dg << std::endl;
    dg++;
  }
  return out;
}